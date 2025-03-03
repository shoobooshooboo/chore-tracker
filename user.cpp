#include "user.hpp"

User::User(void) {}

User::User(uint64_t userID, std::string&& name) :
    mUserID(userID),
    mName(name) {}

void User::addHousehold(std::shared_ptr<Household> householdToJoin) {
    mHouseholds.push_back(householdToJoin);
}

const std::vector<std::shared_ptr<Household>>& User::getHouseholds() const {
    return mHouseholds;
}

const std::string& User::getName(void) const noexcept {
    return mName;
}

uint64_t User::getID(void) const noexcept {
    return mUserID;
}

bool User::setName(const std::string_view name) {
    if (std::find_if_not(std::cbegin(name), std::cend(name), static_cast<int(*)(int)>(std::isalnum)) != name.cend()) {
        return false;
    }
    mName = name;   
    return true;
}
