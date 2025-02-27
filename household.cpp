#include "household.hpp"

void Household::sortChores(SortType sortType) {
    std::ranges::sort(mChores, Household::sortingMethods[sortType]);
}

auto Household::filterChores(bool(*filterCondition)(const Chore&)) const {
    return std::ranges::filter_view(mChores, filterCondition);
}

auto Household::searchForChores(const std::string_view searchTerm) {
    return std::ranges::filter_view(mChores, [searchTerm](const Chore& chore){ return chore.mName.contains(searchTerm); });
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


