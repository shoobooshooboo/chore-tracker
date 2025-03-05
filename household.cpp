#include "household.hpp"

Household::Household(std::string&& name) :
    mName(name) {}

void Household::handleUserJoining(const User& joiningUser) {
    mUsers.emplace_back(joiningUser);
}

void Household::addChore(Chore&& newChore) {
    mChores.push_back(newChore);
}

void Household::sortChores(SortType sortType) {
    std::ranges::sort(mChores, Household::sortingMethods[sortType]);
}

auto Household::filterChores(bool(*filterCondition)(const Chore&)) const {
    return mChores | std::views::filter(filterCondition);
}

auto Household::searchForChores(const std::string_view searchTerm) {
    // lambdas with capture are not convertable to function pointer, hence the distinction from filterChores()
    return mChores | std::views::filter([searchTerm](const Chore& chore){ return chore.mName.contains(searchTerm); });
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


