#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <cstdint>
#include <algorithm>
#include <fstream>
#include <vector>
#include <memory>
#include "user.hpp"

namespace UserManager {
    namespace {
        using container_t = std::vector<std::shared_ptr<User>>;

        container_t loadedUsers;
    }

    [[nodiscard]] container_t::const_iterator findLoadedUser(const uint64_t userID);
    // returns iterator to the user, or end if no user matching ID was found
    container_t::const_iterator loadUser(const uint64_t userID);
    void storeUser(const User& user);
};

#endif