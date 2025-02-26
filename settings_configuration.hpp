#pragma once
#ifndef SETTINGS_CONFIGURATION_HPP
#define SETTINGS_CONFIGURATION_HPP

#include <array> 
#include <cstddef>

struct SettingsConfiguration {
    enum NotificationType : unsigned {
        count
    };
    
    bool mDarkMode;
    std::array<bool, NotificationType::count> mNotifications;

};

#endif