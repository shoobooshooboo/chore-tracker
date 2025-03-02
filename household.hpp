#pragma once
#ifndef HOUSEHOLD_HPP
#define HOUSEHOLD_HPP

#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <memory>
#include <ranges>
#include "chore.hpp"

// forward declared for use in vector<weak_ptr<User>>
class User;

class Household {
private:
    // ways to sort chores for this household
    enum SortType : unsigned {
        NAME,
        DATE,
        PRIORITY,
        LOCATION,
        count 
    };

    static constexpr std::array<bool (*)(const Chore&, const Chore&), SortType::count> sortingMethods {
        // stdlib sorting functions require strict weak ordering, hence < over <=  
        [](const Chore& a, const Chore& b){ return a.mName < b.mName; }, // string::operator<=> performs lexicographical compare 
        [](const Chore& a, const Chore& b){ return a.mDateAndTime < b.mDateAndTime; }, 
        [](const Chore& a, const Chore& b){ return a.mPriority > b.mPriority; },
        [](const Chore& a, const Chore& b){ return a.mLocation < b.mLocation; }
    };

    std::string mName;
    std::vector<Chore> mChores;
    std::vector<std::weak_ptr<User>> mUsers;

public:
    // TODO constructors to be defined when program flow is better defined

    // HouseholdManager interface

    // allows this household to reference a user joining the household 
    void handleUserJoining(std::weak_ptr<User> joiningUser);


    


    // App interface

    void sortChores(SortType sortType);

    [[nodiscard]] const std::vector<Chore>& getChores(void) const noexcept;
    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto filterChores(bool (*filterCondition)(const Chore&)) const;

    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto searchForChores(const std::string_view searchTerm);

    // updates the time of the chore to its next instance if one exists, else deletes the chore
    void expireChoreInstance(decltype(mChores)::iterator toExpire);
};

#endif