#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <algorithm>
#include <cctype>
#include "household.hpp"
#include "settings_configuration.hpp"

class User {
private:
    std::string mName;
    uint64_t mUserID;
    std::vector<std::shared_ptr<Household>> mHouseholds;
    
public:
    // constructors to be defined when program flow is better defined

    // adds a household to this user's vector of households, granting this user shared ownership of the household 
    // NOTE: does not automatically add reference to this user to the household. 
    void addHousehold(std::shared_ptr<Household> householdToJoin);

    [[nodiscard]] const std::vector<std::shared_ptr<Household>>& getHouseholds() const noexcept;
    [[nodiscard]] const std::string& getName(void) const noexcept;
    [[nodiscard]] uint64_t getID(void) const noexcept;
    // names can be valid/invalid -> return type indicates set success
    bool setName(const std::string_view name);

    SettingsConfiguration mSettings;
};

#endif