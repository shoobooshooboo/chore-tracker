#include "chore.hpp"

bool Chore::addAvailability(uint64_t userID, Availability availability) {
    return mAvailabilities.insert_or_assign(std::forward<uint64_t>(userID), std::forward<Availability>(availability)).second;
}