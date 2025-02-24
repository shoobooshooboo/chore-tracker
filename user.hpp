#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include "settingsConfiguration.hpp"

// forward declared for use in vector<shared_ptr<Household>>
class Household; 

class User {
public:
    User(const std::string& name);
    User(std::string&& name);

    void makeHousehold(const std::string& name);
    void addHousehold(const Household& householdToAdd);

    [[nodiscard]] std::shared_ptr<Household> getHousehold(const size_t householdIndex) const;
    [[nodiscard]] const std::string& getName(void) const noexcept;
    [[nodiscard]] uint64_t getID(void) const noexcept;
    // names can be valid/invalid -> return type indicates set success
    bool setName(const std::string& name);
    bool setName(std::string&& name);


    SettingsConfiguration mSettings;
    
private:
    std::string mName;
    uint64_t mUserID;
    std::vector<std::shared_ptr<Household>> mHouseholds;
};

#endif