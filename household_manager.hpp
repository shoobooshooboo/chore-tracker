#pragma once
#ifndef HOUSEHOLD_MANAGER_HPP
#define HOUSEHOLD_MANAGER_HPP

#include <filesystem>
#include <memory>
#include "user.hpp"
#include "household.hpp"
#include "user_manager.hpp"

namespace HouseholdManager {
    namespace {
        constexpr std::filesystem::path householdsFile; 

        // no owning vector in namespace; ownership is solely through users.
    }

    // loads a household from file
    // ONLY USE TO GET THE FIRST INSTANCE OF THE HOUSEHOLD! should not be called multiple times with the same householdID
    // return value is owning pointer of the household, with all users loaded
    std::shared_ptr<Household> loadHousehold(const uint64_t householdID); 

    std::shared_ptr<Household> makeNewHousehold(User& firstMemberUser, Household&& householdInfo);

}  


#endif