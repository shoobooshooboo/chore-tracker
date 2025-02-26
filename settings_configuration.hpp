#pragma once
#ifndef SETTINGS_CONFIGURATION_HPP
#define SETTINGS_CONFIGURATION_HPP

#include <array> 
#include <cstddef>

enum NotificationType : unsigned {
    count
};

struct SettingsConfiguration {
    bool mDarkMode;
    std::array<bool, NotificationType::count> mNotifications;

};

#endif