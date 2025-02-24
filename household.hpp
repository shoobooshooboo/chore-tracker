#pragma once
#ifndef HOUSEHOLD_HPP
#define HOUSEHOLD_HPP

#include <cstdint>
#include <unordered_map>
#include <vector>
#include <memory>
#include <ranges>
#include "chore.hpp"

// forward declared for use in vector<weak_ptr<User>>
class User;

class Household {
private:
    enum class SortType {/* TBD */};

    // TODO: define a container with fixed size that enforces a type specified as a template argument be exclusively used for indexing 
    static std::unordered_map<SortType, bool (*)(Chore, Chore)> sortingMethods;

    std::string mName;
    std::vector<Chore> mChores;
    std::vector<std::weak_ptr<User>> mUsers;

public:
    Household(const std::string& name);
    Household(std::string&& name);

    void sortChores(SortType sortType);
    [[nodiscard]] auto filterChores(bool (*filterCondition)(Chore)) const;

    void addUser(uint64_t userID);
    void removeUser(uint64_t userID);

    [[nodiscard]] Chore& searchForChore(const std::string& searchTerm);
    [[nodiscard]] const std::vector<Chore>& getChores(void) const noexcept;

    void addNextOccurence(const Chore& recurringChore);
    
};

#endif