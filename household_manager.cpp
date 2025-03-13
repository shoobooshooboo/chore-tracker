#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    std::ifstream infile(householdsFile);
    std::string buffer;
    
    const auto matchesID { [householdID](const std::string& buff) -> bool { 
        uint64_t id; 
        return (std::from_chars(buff.data(), buff.data() + buff.size(), id).ec == std::errc{} && id == householdID); 
    } };

    while (true) { // scan for entry matching provided householdID
        std::getline(infile, buffer, ',');
        if (!infile.good()) 
            throw std::invalid_argument {"Household matching householdID does not exist"};

        if (matchesID(buffer)) break;
        else infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::getline(infile, buffer, ','); // gets name field

    // allocate household constructed with its name
    auto householdPtr { std::make_shared<Household>(buffer) };
    
    // gets user ids associated with this household
    std::getline(infile, buffer)
    const std::vector<uint64_t> userIDs { buffer 
        | std::ranges::views::split(',')
        | std::ranges::views::transform([](auto&& subrange){ return std::string_view(subrange); })
        | std::ranges::views::transform(strToInt<uint64_t>)
        | std::ranges::to<std::vector<uint64_t>>()
    };

    // adds users
    for (uint64_t userID : userIDs) { 
        mutuallyLink(*UserManager::loadUser(std::forward<uint64_t>(userID)), householdPtr);
    }

    // adds chores
    while (std::getline(infile, buffer), buffer != "</>") { 
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

            newChore.addAvailability(
                std::forward<uint64_t>(userID), 
                strToEnum<Availability>(std::string_view(*++it))    
            );
        }
        
        householdPtr->addChore(std::move(newChore));
    }

    return householdPtr;
}

std::shared_ptr<Household> HouseholdManager::makeNewHousehold(User& firstMemberUser, Household&& householdInfo) {
    auto householdPtr{ std::make_shared<Household>(householdInfo) };

    mutuallyLink(firstMemberUser, householdPtr);
    
    return householdPtr;
}

void HouseholdManager::mutuallyLink(User& user, const std::shared_ptr<Household>& household) {
    user.addHousehold(household);
    household->handleUserJoining(std::move(user));
}
