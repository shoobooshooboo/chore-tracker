#pragma once
#ifndef HOUSEHOLD_HPP
#define HOUSEHOLD_HPP

#include <cstdint>
#include <array>
#include <vector>
#include <memory>
#include <ranges>
#include "chore.hpp"
#include "userManager.hpp"

// forward declared for use in vector<weak_ptr<User>>
class User;

class Household {
private:
    // ways to sort chores for this household
    enum SortType : unsigned {
        NAME,
        DATE,
        PRIORITY,
        count 
    };

    static constexpr std::array<bool (*)(const Chore&, const Chore&), SortType::count> sortingMethods {
        // stdlib sorting functions require strict weak ordering, hence < over <=  
        [](const Chore& a, const Chore& b){ return a.mName < b.mName; }, // string::operator<=> performs lexicographical compare 
        [](const Chore& a, const Chore& b){ return a.mDateAndTime < b.mDateAndTime; }, 
        [](const Chore& a, const Chore& b){ return a.mPriority < b.mPriority; }
    };

    std::string mName;
    std::vector<Chore> mChores;
    std::vector<std::weak_ptr<User>> mUsers;

public:
    Household(const std::string& name);
    Household(std::string&& name);

    void sortChores(SortType sortType);
    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto filterChores(bool (*filterCondition)(const Chore&)) const;

    // false if user with this ID does not exist
    bool addUser(const uint64_t userID);
    void removeUser(const uint64_t userID);

    // full return type is lengthy, is std::ranges::filter_view<...>
    [[nodiscard]] auto searchForChores(const std::string_view searchTerm);
    [[nodiscard]] const std::vector<Chore>& getChores(void) const noexcept;

    // updates the time of the chore to its next instance if one exists, else deletes the chore
    void expireChoreInstance(decltype(mChores)::iterator toExpire);
};

#endif