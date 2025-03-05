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
    uint64_t mUserID;
    std::string mName;
    std::vector<std::shared_ptr<Household>> mHouseholds;
    
public:
    User(void);
    User(uint64_t userID, std::string&& name);

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

[[nodiscard]] bool isAllAlphanum(const std::string_view str);

#endif