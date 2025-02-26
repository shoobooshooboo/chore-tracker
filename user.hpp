#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include "settings_configuration.hpp"

// forward declared for use in vector<shared_ptr<Household>>
class Household; 

class User {
private:
    std::string mName;
    uint64_t mUserID;
    std::vector<std::shared_ptr<Household>> mHouseholds;
    
public:
    // constructors to be defined when program flow is better defined

    void makeHousehold(const std::string& name);

    [[nodiscard]] const std::vector<std::shared_ptr<Household>>& getHouseholds() const;
    [[nodiscard]] const std::string& getName(void) const noexcept;
    [[nodiscard]] uint64_t getID(void) const noexcept;
    // names can be valid/invalid -> return type indicates set success
    bool setName(const std::string_view name);

    SettingsConfiguration mSettings;
};

#endif