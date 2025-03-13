#include "chore.hpp"

Chore::Chore(const std::string& name, timepoint_t dateTime, Priority priority, const std::string& location) : 
    mName(name), 
    mDateAndTime(dateTime),
    mPriority(priority), 
    mLocation(location),
    mRecurrenceInterval(std::nullopt) {}

Chore::Chore(const std::string& name, timepoint_t dateTime, Priority priority, const std::string& location, timepoint_t::duration recurrenceInterval) :
    mName(name), 
    mDateAndTime(dateTime),
    mPriority(priority), 
    mLocation(location),
    mRecurrenceInterval(std::in_place, recurrenceInterval) {}

bool Chore::addAvailability(const uint64_t userID, const Availability availability) {
    return mAvailabilities.insert_or_assign(userID, availability).second;
}