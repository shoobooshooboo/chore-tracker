#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <cstdint>
#include <algorithm>
#include <fstream>
#include <print>
#include <filesystem>
#include <limits>
#include <vector>
#include <memory>
#include "user.hpp"

namespace UserManager {
    namespace {
        // entries are to be formatted as follows:
        // id number,username,password|first last,household_id,next_household_id,...,last_household_id\n
        const std::filesystem::path userFile{"users.csv"};

        using container_t = std::vector<std::shared_ptr<User>>;

        container_t loadedUsers;
    }

    [[nodiscard]] container_t::const_iterator findLoadedUser(const uint64_t userID);
    // returns iterator to the user, or end if no user matching ID was found
    container_t::const_iterator loadUser(const uint64_t userID);
    void createUserToFile(const User& user, const std::string& username, const std::string& password, const uint64_t firstHousehold);
};

#endif