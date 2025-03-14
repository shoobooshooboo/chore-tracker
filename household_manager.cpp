#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    std::ifstream infile(householdsFile);
    std::string buffer;
    
    do { // scan for entry matching provided householdID
        // @ indicates a new chore
        infile.ignore(std::numeric_limits<std::streamsize>::max(), '@');
        std::getline(infile, buffer, ',');
        if (!infile.good()) 
            throw std::invalid_argument {"Household matching householdID does not exist"};

    } while (strToInt<uint64_t>(buffer) != householdID);
    
    std::getline(infile, buffer, ','); // name
    auto householdPtr { std::make_shared<Household>(std::move(buffer)) };
    
    // gets user ids associated with this household
    std::getline(infile, buffer);
    const std::vector<uint64_t> userIDs { buffer 
        | std::ranges::views::split(',')
        | std::ranges::views::transform([](auto&& subrange){ return std::string_view(subrange); })
        | std::ranges::views::transform(strToInt<uint64_t>)
        | std::ranges::to<std::vector<uint64_t>>()
    };

    // adds users
    for (uint64_t userID : userIDs) { 
        mutuallyLink(*UserManager::loadUser(userID), householdPtr);
    }

    // adds chores
    while (std::getline(infile, buffer), buffer.front() != '@') { 
        householdPtr->addChore(parseChoreLine(buffer, userIDs));
    }

    return householdPtr;
}

std::shared_ptr<Household> HouseholdManager::makeNewHousehold(User& firstMemberUser, Household&& householdInfo) {
    auto householdPtr{ std::make_shared<Household>(householdInfo) };

    mutuallyLink(firstMemberUser, householdPtr);
    
    return householdPtr;
}

Chore HouseholdManager::parseChoreLine(const std::string& buffer, const std::vector<uint64_t>& userIDs) {
    // name, time, completion, priority, location, interval, availabilities...
    auto choreFields { buffer | std::views::split(',') };
    auto it { choreFields.cbegin() };
    
    Chore newChore( // name, time, completion, priority, location, interval
        std::ranges::to<std::string>(*it),
        strToChrono<Chore::timepoint_t>(std::string_view(*++it)),
        std::string_view(*++it) != "0",
        strToEnum<Priority>(std::string_view(*++it)),
        std::ranges::to<std::string>(*++it),
        strToChrono<Chore::timepoint_t::duration>(std::string_view(*++it))
    );

    for (uint64_t userID : userIDs) { // availabilities
        // ensure that there are no more users than availabilities
        assert(std::next(it) != choreFields.cend());
        [[assume(std::next(it) != choreFields.cend())]];

        newChore.addAvailability(std::forward<uint64_t>(userID), strToEnum<Availability>(std::string_view(*++it)));
    }
    return newChore;
}

void HouseholdManager::mutuallyLink(User& user, const std::shared_ptr<Household>& household) {
    user.addHousehold(household);
    household->handleUserJoining(user);
}
