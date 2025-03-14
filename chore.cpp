#include "chore.hpp"

Chore::Chore(std::string&& name, timepoint_t dateTime, bool completionStatus, Priority priority, std::string&& location, timepoint_t::duration interval) :
    mName(std::forward<std::string>(name)),
    mDateAndTime(dateTime),
    mCompletionStatus(completionStatus),
    mPriority(priority),
    mLocation(std::forward<std::string>(location)),
    mRecurrenceInterval(interval) 
{
    if (mRecurrenceInterval == timepoint_t::duration::zero()) 
        mRecurrenceInterval.reset();
}


bool Chore::addAvailability(uint64_t userID, Availability availability) {
    return mAvailabilities.insert_or_assign(std::forward<uint64_t>(userID), std::forward<Availability>(availability)).second;
}