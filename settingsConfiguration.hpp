#pragma once
#ifndef SETTINGS_CONFIGURATION_HPP
#define SETTINGS_CONFIGURATION_HPP

#include <array> 
#include <cstddef>

enum class NotificationType {
    NOTIFICATION_TYPE_COUNT
};

struct SettingsConfiguration {
    bool mDarkMode;
    // TODO: define a container with fixed size that enforces a type specified as a template argument be exclusively used for indexing 
    std::array<bool, static_cast<size_t>(NotificationType::NOTIFICATION_TYPE_COUNT)> mNotifications;

};

#endif