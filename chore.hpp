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
    CANNOT_DO,
    INCONVENIENT,
    CONVENIENT,
    WILL_DO,
    Count
};

struct Chore {
public:
    // return value indicates success 
    bool addAvailability(const uint64_t userID, const Availability availability);

    std::string mName;
    std::chrono::time_point<std::chrono::system_clock> mDateAndTime;
    bool mCompletionStatus;
    std::string mLocation;
    std::optional<decltype(mDateAndTime)::duration> mRecurrenceInterval;
private:
    // maps userIDs to availabilities
    std::unordered_map<uint64_t, Availability> mAvailabilities;
};

#endif
