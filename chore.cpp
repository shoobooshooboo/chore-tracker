#include "chore.hpp"

bool Chore::addAvailability(const uint64_t userID, const Availability availability) {
    return mAvailabilities.insert_or_assign(userID, availability).second;
}