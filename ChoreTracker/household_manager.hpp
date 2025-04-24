#pragma once
#ifndef HOUSEHOLD_MANAGER_HPP
#define HOUSEHOLD_MANAGER_HPP

#include <cassert>
#include <filesystem>
#include <fstream>
#include <type_traits>
#include <memory>
#include <exception>
#include <span>
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
        std::filesystem::path householdsFile{"../houseFile.csv"};

        // no owning vector in namespace; ownership is solely through users.
    }

    // loads a household from file
    // ONLY USE TO GET THE FIRST INSTANCE OF THE HOUSEHOLD! should not be called multiple times with the same householdID
    // return value is owning pointer of the household, with all users loaded
    std::shared_ptr<Household> loadHousehold(const uint64_t householdID); 

    std::vector<std::shared_ptr<Household>> getLocalHouseholds(const uint64_t localUserID);

    std::shared_ptr<Household> makeNewHousehold(User& firstMemberUser, Household&& householdInfo);

    void createHouseholdToFile(const Household& house);

    Chore parseChoreLine(const std::string& buffer, const std::vector<uint64_t>& userIDs);

    void mutuallyLink(User& user, const std::shared_ptr<Household>& household);

    template<class Enum>
    Enum strToEnum(std::string_view sv) {
        std::underlying_type_t<Enum> val;
        if (std::from_chars(sv.data(), sv.data() + sv.size(), val).ec != std::errc()) 
            throw std::runtime_error{"bad parse"};
        return static_cast<Enum>(val);
    }

    template<class TimepointType>
    TimepointType strToTimepoint(std::string_view sv) {
        std::tm tmb;
<<<<<<< Updated upstream
        std::istringstream { std::string(sv) } >> std::get_time(&tmb, "%Y-%m-%w %T");
        return ChronoType(std::chrono::system_clock::from_time_t(std::mktime(&tmb)).time_since_epoch());
=======
        std::istringstream{ std::string(sv) } >> std::get_time(&tmb, "%Y-%m-%d %T");
        return TimepointType(std::chrono::system_clock::from_time_t(std::mktime(&tmb)));
>>>>>>> Stashed changes
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
