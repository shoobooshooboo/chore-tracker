#pragma once
#ifndef HOUSEHOLD_MANAGER_HPP
#define HOUSEHOLD_MANAGER_HPP

#include <filesystem>
#include <memory>
#include "user.hpp"
#include "household.hpp"
#include "user_manager.hpp"

namespace HouseholdManager {

    // non visually printed characters
    // they do work as delims even if you can't see them
    namespace Separators {
        constexpr char FILE {28};
        constexpr char GROUP {29};
        constexpr char REC {30};
        constexpr char UNIT {31};
    }

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