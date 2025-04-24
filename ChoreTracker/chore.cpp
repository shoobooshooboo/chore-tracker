#include "chore.hpp"

Chore::Chore(std::string&& name, timepoint_t dateTime, bool completionStatus, Priority priority, std::string&& location, unsigned intervalDays) :
    mName(std::forward<std::string>(name)),
    mDateAndTime(dateTime),
    mCompletionStatus(completionStatus),
    mPriority(priority),
    mLocation(std::forward<std::string>(location))
{
    if (mRecurrenceInterval != 0) 
        mRecurrenceInterval = intervalDays;
}


bool Chore::addAvailability(uint64_t userID, Availability availability) {
    return mAvailabilities.insert_or_assign(std::forward<uint64_t>(userID), std::forward<Availability>(availability)).second;
}