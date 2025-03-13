#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    std::ifstream infile(householdsFile);
    std::string buffer;

    do { // search for household info corresponding to householdID
        std::getline(infile, buffer, ',');
        
        if (!infile.good()) throw std::invalid_argument {"Household matching householdID does not exist"};

    } while (!std::isdigit(buffer.front()) || std::stoull(buffer) != householdID);

    std::getline(infile, buffer); // gets the rest of ID line

    // name, userIDs...
    auto houseFields { buffer | std::views::split(',') };

    // allocate household constructed with its name
    auto householdPtr { std::make_shared<Household>(houseFields.front() | std::ranges::to<std::string>()) };
    
    const std::vector<uint64_t> userIDs { houseFields 
        | std::ranges::views::drop(1)
        | std::ranges::views::transform([](auto idString){ return std::stoull(idString | std::ranges::to<std::string>()); })
        | std::ranges::to<std::vector<uint64_t>>()
    };

    // adds users
    for (uint64_t userID : userIDs) { 
        mutuallyLink(*UserManager::loadUser(std::forward<uint64_t>(userID)), householdPtr);
    }

    // adds chores
    while ([&infile, &buffer]{ std::getline(infile, buffer); return buffer != "</>"; }()) { 
        // name, time, completion, priority, location, interval, availabilities...
        auto choreFields { buffer | std::views::split(',') };
        auto it { choreFields.cbegin() };
        
        Chore newChore( // name, time, completion, priority, location
            *it | std::ranges::to<std::string>(),
            strToChrono<Chore::timepoint_t>(std::string_view(*++it)),
            std::string_view(*++it) != "0",
            strToEnum<Priority>(std::string_view(*++it)),
            *++it | std::ranges::to<std::string>()
        );

        // interval
        auto d { strToChrono<Chore::timepoint_t::duration>(std::string_view(*++it)) };
        if (d != decltype(d)::zero()) 
            newChore.mRecurrenceInterval = d;

        for (uint64_t userID : userIDs) { // availabilities
            // ensure that there are no more users than availabilities
            assert(std::next(it) != choreFields.cend());
            [[assume(std::next(it) != choreFields.cend())]];

            const std::string_view svAvailability(*++it);
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
