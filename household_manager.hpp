#pragma once
#ifndef HOUSEHOLD_MANAGER_HPP
#define HOUSEHOLD_MANAGER_HPP

#include <cassert>
#include <filesystem>
#include <type_traits>
#include <memory>
#include <exception>
#include <charconv>
#include <cctype>
#include <sstream>
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
        std::filesystem::path householdsFile{"houseFile.csv"}; 

        // no owning vector in namespace; ownership is solely through users.
    }

    // loads a household from file
    // ONLY USE TO GET THE FIRST INSTANCE OF THE HOUSEHOLD! should not be called multiple times with the same householdID
    // return value is owning pointer of the household, with all users loaded
    std::shared_ptr<Household> loadHousehold(const uint64_t householdID); 

    std::shared_ptr<Household> makeNewHousehold(User& firstMemberUser, Household&& householdInfo);

    void mutuallyLink(User& user, const std::shared_ptr<Household>& household);

    template<class Enum>
    Enum strToEnum(std::string_view sv) {
        std::underlying_type_t<Enum> val;
        if (std::from_chars(sv.data(), sv.data() + sv.size(), val).ec != std::errc()) 
            throw std::runtime_error{"bad parse"};
        return static_cast<Enum>(val);
    }

    template<class ChronoType>
    ChronoType strToChrono(std::string_view sv) {
        ChronoType t{};
        std::istringstream { std::string(sv) } >> std::chrono::parse("%F %T", t);
        return t;
    }

    template<class IntegralType>
    IntegralType strToInt(std::string_view sv) {
        IntegralType val;
        if (std::from_chars(sv.data(), sv.data() + sv.size(), val).ec != std::errc()) 
            throw std::runtime_error{"bad parse"};
        return val;
    }
    
}  


#endif