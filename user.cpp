#include "user.hpp"

std::shared_ptr<Household> User::getHousehold(const size_t householdIndex) const {
    return mHouseholds[householdIndex];
}

const std::string& User::getName(void) const noexcept {
    return mName;
}

uint64_t User::getID(void) const noexcept {
    return mUserID;
}
