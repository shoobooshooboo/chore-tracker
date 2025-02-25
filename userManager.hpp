#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <vector>
#include <algorithm>
#include <filesystem>
#include "user.hpp"

namespace UserManager {
    namespace {
        constexpr std::filesystem::path usersFile; 
        
        std::vector<std::shared_ptr<User>> loadedUsers;
    }
    
    [[nodiscard]] bool isLoaded(const uint64_t userID);
    [[nodiscard]] decltype(loadedUsers)::const_iterator findLoadedUser(const uint64_t userID);
    // returns iterator to the user, or end if no user matching ID was found
    decltype(loadedUsers)::const_iterator loadUser(const uint64_t userID);
    void storeUser(const User& user);
};

#endif