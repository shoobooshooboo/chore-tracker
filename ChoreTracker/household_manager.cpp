#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    std::ifstream infile(householdsFile);
    std::string buffer;
    
    do { // scan for entry matching provided householdID
        // @ indicates a new household
        infile.ignore(std::numeric_limits<std::streamsize>::max(), '@');
        std::getline(infile, buffer, ',');
        if (!infile.good()) 
            throw std::invalid_argument {"Household matching householdID does not exist"};

    } while (strToInt<uint64_t>(buffer) != householdID);

    std::getline(infile, buffer, ','); // name
    auto householdPtr { std::make_shared<Household>(householdID, std::move(buffer)) };
    
    // gets user ids associated with this household
    std::getline(infile, buffer);
    auto r { buffer
        | std::ranges::views::split(',')
        | std::ranges::views::transform([](auto&& subrange){ return std::string_view(subrange); })
        | std::ranges::views::transform(strToInt<uint64_t>)
    };

    std::vector<uint64_t> userIDs;
    userIDs.assign(r.cbegin(), r.cend());

    // adds users
    for (uint64_t userID : userIDs) { 
        mutuallyLink(UserManager::loadUser(userID), householdPtr);
    }

    // adds chores
    while (std::getline(infile, buffer), buffer.front() != '@') { 
        householdPtr->addChore(parseChoreLine(buffer, userIDs));
    }

    return householdPtr;
}

std::vector<std::shared_ptr<Household>> HouseholdManager::getLocalHouseholds(const uint64_t localUserID) {
    std::vector<std::shared_ptr<Household>> out;
    std::ifstream housestream(householdsFile);
    while (housestream) {
        housestream.ignore(std::numeric_limits<std::streamsize>::max(), '@');
        housestream.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        housestream.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        // ids text begins
        std::string idsString;
        std::getline(housestream, idsString);
        for (uint64_t id : idsString
            | std::views::split(',')
            | std::views::transform([](auto r){ return std::stoull(std::string(r.cbegin(), r.cend())); })) 
        {
            out.push_back(loadHousehold(id));
        }
    }
    return out;
}

std::shared_ptr<Household> HouseholdManager::makeNewHousehold(User& firstMemberUser, Household&& householdInfo) {
    auto householdPtr{ std::make_shared<Household>(householdInfo) };

    mutuallyLink(firstMemberUser, householdPtr);
    
    return householdPtr;
}

void HouseholdManager::createHouseholdToFile(const Household& house)  {
    std::ofstream householdsStream(householdsFile, std::ios::app);
    householdsStream << std::format("@{},{}", house.getID(), house.getName());
    for (uint64_t id : house.getUsers() 
        | std::views::transform([](const User& user){ return user.getID(); })) {
        householdsStream << id;
    }
    householdsStream << '\n';
    for (const Chore& chore : house.getChores()) {
        householdsStream << std::format("{},{},{},{},{},{}", 
            chore.mName, 
            chore.mDateAndTime, 
            static_cast<int>(chore.mCompletionStatus), 
            static_cast<int>(chore.mPriority), 
            chore.mLocation,
            std::chrono::system_clock::time_point(*chore.mRecurrenceInterval)  
        );
        for (uint64_t id : house.getUsers() 
            | std::views::transform([](const User& user){ return user.getID(); })) {
            householdsStream << std::format(",{}", static_cast<int>(chore.mAvailabilities.at(id)));
        }
        householdsStream << '\n';
    }    
}

Chore HouseholdManager::parseChoreLine(const std::string& buffer, const std::vector<uint64_t>& userIDs) {
    // name, time, completion, priority, location, interval, availabilities...
    auto choreFields { buffer | std::views::split(',') };
    auto it { choreFields.cbegin() };
    
    Chore newChore( // name, time, completion, priority, location, interval
        std::string(std::string_view(*it)),
        strToChrono<Chore::timepoint_t>(std::string_view(*++it)),
        std::string_view(*++it) != "0",
        strToEnum<Priority>(std::string_view(*++it)),
        std::string(std::string_view(*++it)),
        strToChrono<Chore::timepoint_t::duration>(std::string_view(*++it))
    );

    for (uint64_t userID : userIDs) { // availabilities
        // ensure that there are no more users than availabilities
        assert(std::next(it) != choreFields.cend());

        newChore.addAvailability(userID, strToEnum<Availability>(std::string_view(*++it)));
    }
    return newChore;
}

void HouseholdManager::mutuallyLink(User& user, const std::shared_ptr<Household>& household) {
    user.addHousehold(household);
    household->handleUserJoining(user);
}
