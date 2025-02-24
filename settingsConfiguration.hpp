#pragma once
#ifndef SETTINGS_CONFIGURATION_HPP
#define SETTINGS_CONFIGURATION_HPP

#include <array> 
#include <cstddef>

enum NotificationType : unsigned {
    Count
};

struct SettingsConfiguration {
    bool mDarkMode;
    std::array<bool, NotificationType::Count> mNotifications;

};

#endif