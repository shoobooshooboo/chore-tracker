#pragma once
#ifndef CHORE_HPP
#define CHORE_HPP

#include <cstdint>
#include <optional>
#include <chrono>
#include <string>
#include <unordered_map>

//Availability indicates the availability of some user to complete a particular chore. 
enum class Availability {
    WILL_DO,
    CONVENIENT,
    INCONVENIENT,
    CANNOT_DO,
    AVAILABILITY_TYPE_COUNT
};

struct Chore {
public:
    // return value indicates success 
    bool addAvailability(const uint64_t userID, const Availability availability);

    std::string mName;
    std::chrono::time_point<std::chrono::system_clock> mDateAndTime;
    bool mCompletionStatus;
    std::string mLocation;
    std::optional<std::chrono::duration<decltype(mDateAndTime)::rep, decltype(mDateAndTime)::duration::period>> mRecurrenceInterval;
private:
    std::unordered_map<uint64_t, Availability> mAvailabilities;
};

#endif