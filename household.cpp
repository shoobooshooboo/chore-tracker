#include "household.hpp"

void Household::sortChores(SortType sortType) {
    std::ranges::sort(mChores, sortingMethods[sortType]);
}

auto Household::filterChores(bool(*filterCondition)(const Chore&)) const {
    return std::ranges::filter_view(mChores, filterCondition);
}

bool Household::addUser(const uint64_t userID) {
    const auto it{UserManager::findLoadedUser(userID)};
    if (it != UserManager::loadedUsers.cend()) {
        // as findLoadedUser returns cend if no match is found, 
        // that must be checked for to prevent nullptr dereference
        mUsers.push_back(std::weak_ptr<User>(*it));
        return true;
    } else
        return false;
        
}

void Household::removeUser(const uint64_t userID) {
    mUsers.erase(std::ranges::find_if(mUsers,
        [userID](const User& user){ return userID == user.getID(); }, 
        [](const std::weak_ptr<User>& ptr){ return *ptr.lock();}
    ));
}

auto Household::searchForChores(const std::string_view searchTerm) {
    return std::ranges::filter_view(mChores, [searchTerm](const Chore& chore){return chore.mName.contains(searchTerm); });
}

const std::vector<Chore>& Household::getChores(void) const noexcept {
    return mChores;
}

void Household::expireChoreInstance(decltype(mChores)::iterator toExpire) {
    if (toExpire->mRecurrenceInterval) {
        toExpire->mDateAndTime += *(toExpire->mRecurrenceInterval);
    } else {
        mChores.erase(toExpire);
    }
}


