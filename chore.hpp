#pragma once
#ifndef CHORE_HPP
#define CHORE_HPP

#include <cstdint>
#include <optional>
#include <chrono>
#include <string>
#include <unordered_map>

// indicates the availability of some user to complete a particular chore. 
enum class Availability : unsigned {
    UNSPECIFIED,
    CANNOT_DO,
    INCONVENIENT,
    CONVENIENT,
    WILL_DO,
    count
};

enum class Priority : unsigned {
    LOW,
    MEDIUM,
    HIGH,
    IMMINENT,
    count
};

struct Chore {
public:
    using timepoint_t = std::chrono::time_point<std::chrono::system_clock>;

    Chore(std::string&& name, timepoint_t dateTime, bool completionStatus, Priority priority, std::string&& location, timepoint_t::duration duration);
    
    // return value indicates success 
    bool addAvailability(uint64_t userID, Availability availability);
    
    std::string mName;
    timepoint_t mDateAndTime;
    bool mCompletionStatus;
    Priority mPriority;
    std::string mLocation;
    
    std::optional<timepoint_t::duration> mRecurrenceInterval;

private:
    // maps userIDs to availabilities
    std::unordered_map<uint64_t, Availability> mAvailabilities;
};

#endif
