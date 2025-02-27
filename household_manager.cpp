#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    Household house;

    // TODO read all data into household from file

    // TODO read the userIDs for this household from file and plug into below

    auto householdPtr{ std::make_shared<Household>(house) };

    while (true /*TODO actual condition should be while users left from this household*/) {
        uint64_t userID{/*TODO should have value from file*/};

        const auto user{ UserManager::loadUser(userID) };

        householdPtr->handleUserJoining(std::weak_ptr(*user));
        (*user)->addHousehold(householdPtr);
    }

    return householdPtr;
}