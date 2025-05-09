#pragma once
#ifndef HOUSEHOLD_HPP
#define HOUSEHOLD_HPP

#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <functional>
#include <ranges>
#include "chore.hpp"

// forward declared for use in vector<reference_wrapper<User>>
class User;

class Household {
public:
    // ways to sort chores for this household
    enum SortType : unsigned {
        NAME,
        DATE,
        PRIORITY,
        LOCATION,
        count
    };
private:
    static constexpr std::array<bool (*)(const Chore&, const Chore&), SortType::count> sortingMethods {
        // stdlib sorting functions require strict weak ordering, hence < over <=  
        [](const Chore& a, const Chore& b){ return a.mName < b.mName; }, // string::operator<=> performs lexicographical compare 
        [](const Chore& a, const Chore& b){ return a.mDateAndTime < b.mDateAndTime; }, 
        [](const Chore& a, const Chore& b){ return a.mPriority > b.mPriority; },
        [](const Chore& a, const Chore& b){ return a.mLocation < b.mLocation; }
    };

    uint64_t mId;
    std::string mName;
    std::vector<Chore> mChores;
    std::vector<std::reference_wrapper<User>> mUsers;

public:

    Household(uint64_t id, std::string&& name);

    [[nodiscard]] std::string_view getName(void) const noexcept;

    [[nodiscard]] uint64_t getID(void) const noexcept;

    [[nodiscard]] const std::vector<std::reference_wrapper<User>>& getUsers(void) const noexcept;
    // HouseholdManager interface

    // allows this household to reference a user joining the household 
    void handleUserJoining(User& joiningUser);


    


    // App interface
    void addChore(Chore&& newChore);

    void removeChore(decltype(mChores)::const_iterator toRemove);

    void removeChore(int index);

    void sortChores(SortType sortType);

    void setChoreStatus(int index, bool status);

    [[nodiscard]] const std::vector<Chore>& getChores(void) const noexcept;
    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto filterChores(bool (*filterCondition)(const Chore&)) const;

    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto searchForChores(const std::string_view searchTerm);

    // updates the time of the chore to its next instance if one exists, else deletes the chore
    void expireChoreInstance(decltype(mChores)::iterator toExpire);

    void editChore(int index, std::string name, Chore::timepoint_t dateTime, bool completionStatus, Priority priority, std::string location, unsigned intervalDays);
};

#endif
