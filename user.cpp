#include "user.hpp"

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
    if (std::ranges::find_if(name, [](const decltype(name)::value_type c){ return !(isalpha(c)); }) != name.cend()) {
        return false;
    }
    mName = name;
    return true;
}
