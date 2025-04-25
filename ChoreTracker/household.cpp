#include "household.hpp"

Household::Household(uint64_t id, std::string&& name) :
    mId(id),
    mName(name) {}

std::string_view Household::getName(void) const noexcept {
    return { mName.data(), mName.size() };
}

uint64_t Household::getID(void) const noexcept {
    return mId;
}

const std::vector<std::reference_wrapper<User>>& Household::getUsers(void) const noexcept {
    return mUsers;
}

void Household::handleUserJoining(User& joiningUser) {
    mUsers.push_back(std::ref(joiningUser));
}

void Household::addChore(Chore&& newChore) {
    mChores.push_back(std::forward<Chore>(newChore));
}

void Household::removeChore(decltype(mChores)::const_iterator toRemove) {
    mChores.erase(toRemove);
}

void Household::removeChore(int index){
    mChores.erase(mChores.begin() + index);
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

void Household::setChoreStatus(int index, bool status){
    mChores[index].mCompletionStatus = status;
}

void Household::expireChoreInstance(decltype(mChores)::iterator toExpire) {
    if (toExpire->mRecurrenceInterval) {
        toExpire->mDateAndTime += toExpire->mRecurrenceInterval.value() * (std::chrono::duration_cast<std::chrono::system_clock::duration>(std::chrono::days(1)));
    } else {
        mChores.erase(toExpire);
    }
}

void Household::editChore(int index, std::string name, Chore::timepoint_t dateTime,
                          bool completionStatus, Priority priority, std::string location, unsigned intervalDays){
    mChores[index] = Chore(std::move(name), dateTime, completionStatus, priority, std::move(location), intervalDays);
}
