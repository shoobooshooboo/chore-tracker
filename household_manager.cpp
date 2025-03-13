#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    std::string buffer;
    std::ifstream infile(householdsFile);

    do { // search for household info corresponding to householdID
        std::getline(infile, buffer, ',');
        
        if (!infile.good()) throw std::invalid_argument {"Household matching householdID does not exist"};

    } while (!std::isdigit(buffer.front()) || std::stoull(buffer) != householdID);

    std::getline(infile, buffer); // gets the rest of ID line

    // name, userIDs...
    auto houseFields { buffer | std::views::split(',') };

    // allocate household constructed with its name
    auto householdPtr { std::make_shared<Household>(houseFields.front()) };
    
    auto userIDs { houseFields 
        | std::ranges::views::drop(1)
        | std::ranges::views::transform([](auto idString){ return std::stoull(idString | std::ranges::to<std::string>()); })
        | std::ranges::to<std::vector<uint64_t>>()
    };

    // adds users
    for (uint64_t userID : userIDs) { 
        auto user { UserManager::loadUser(std::forward<uint64_t>(userID)) };

        householdPtr->handleUserJoining(*user);
        user->addHousehold(householdPtr);
    }

    std::getline(infile, buffer);
    while (buffer != "</>") { // adds chores
        // name, time, completion, priority, location, interval, availabilities...
        auto choreFields { buffer | std::views::split(',') };
        auto it { choreFields.cbegin() };
        
        Chore newChore;
        newChore.mName = *it | std::ranges::to<std::string>();
        
        std::istringstream { *(++it) | std::ranges::to<std::string>() } 
            >> std::chrono::parse("%F %T", newChore.mDateAndTime);
        
        newChore.mCompletionStatus = std::string_view(*(++it)) != "0";
        
        newChore.mPriority = static_cast<Priority>(std::stoul(*(++it) | std::ranges::to<std::string>()));
        
        newChore.mLocation = *(++it) | std::ranges::to<std::string>();
        
        Chore::timepoint_t::duration d;
        std::istringstream { *(++it) | std::ranges::to<std::string>() }
            >> std::chrono::parse("%F %T", d);

        if (d != decltype(d)::zero()) 
            newChore.mRecurrenceInterval = d;

        for (uint64_t userID : userIDs) {
            // ensure that there are no more users than availabilities
            assert(std::next(it) != choreFields.cend());
            [[assume(std::next(it) != choreFields.cend())]];

            newChore.addAvailability(
                std::forward<uint64_t>(userID), 
                static_cast<Availability>(std::stoul(*(++it) | std::ranges::to<std::string>()))
            );
        }
        
        householdPtr->addChore(std::move(newChore));
        std::getline(infile, buffer);
    }

    return householdPtr;
}

std::shared_ptr<Household> HouseholdManager::makeNewHousehold(User& firstMemberUser, Household&& householdInfo) {
    auto householdPtr{ std::make_shared<Household>(householdInfo) };

    householdPtr->handleUserJoining(firstMemberUser);
    firstMemberUser.addHousehold(householdPtr);
    
    return householdPtr;
}
