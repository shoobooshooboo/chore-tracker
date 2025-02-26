#include "user.hpp"

const std::vector<std::shared_ptr<Household>>& User::getHouseholds() const {
    return mHouseholds;
}

const std::string& User::getName(void) const noexcept {
    return mName;
}

uint64_t User::getID(void) const noexcept {
    return mUserID;
}
