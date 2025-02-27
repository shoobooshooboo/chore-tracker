#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <algorithm>
#include "household.hpp"
#include "settings_configuration.hpp"

class User {
private:
    std::string mName;
    uint64_t mUserID;
    std::vector<std::shared_ptr<Household>> mHouseholds;
    
public:
    // constructors to be defined when program flow is better defined

    // creates a household with this user, with this user initially the sole owner
    // writes this households information to file via HouseholdManager
    void makeHousehold(/* household creation parameters */);

    // adds a household to this user's vector of households, granting this user shared ownership of the household 
    void addHousehold(std::shared_ptr<Household> householdToJoin);

    // finds or loads the user with the given userID, and adds them to the given household.
    void addOtherUserToHousehold(const uint64_t userID, const std::shared_ptr<Household>) const; 

    [[nodiscard]] const std::vector<std::shared_ptr<Household>>& getHouseholds() const noexcept;
    [[nodiscard]] const std::string& getName(void) const noexcept;
    [[nodiscard]] uint64_t getID(void) const noexcept;
    // names can be valid/invalid -> return type indicates set success
    bool setName(const std::string_view name);

    SettingsConfiguration mSettings;
};

#endif