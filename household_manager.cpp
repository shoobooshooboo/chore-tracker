#include "household_manager.hpp"

std::shared_ptr<Household> HouseholdManager::loadHousehold(const uint64_t householdID) {
    // TODO read all data into household from file
    std::string buffer;
    std::ifstream infile("houseFile.csv");
    while (infile.good())
    {
        std::getline(infile, buffer,',');
        if (buffer[0] >= '0' && buffer[0] <= '9' && std::stoull(buffer) == householdID) // found the household
            break;
    }
    if (!infile.good()) // went through file and did not find the ID
    {
        throw std::invalid_argument {"Shit."}; // what happened
    }

    
    getline(infile, buffer); // gets the rest of ID line
    // TODO read the userIDs for this household from file and plug into below
    buffer.erase(0,1); // gets rid of first ,
    Household house(buffer.substr(0,buffer.find(','))); 
    buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
    
    auto householdPtr{ std::make_shared<Household>(house) };

    std::vector<uint64_t> ids;

    while (buffer != "<chores>") { // adds users
        getline(infile, buffer);
        std::string id {buffer.substr(0,buffer.find(','))};

        uint64_t userID{std::stoull(id)};
        ids.push_back(userID);
        auto user{ UserManager::loadUser(userID) };

        householdPtr->handleUserJoining(*user);
        user->addHousehold(householdPtr);

        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
    }
    getline(infile, buffer);
    while (buffer != "</chores>") // adds chores
    {
        Chore newChore;
        // FirstChore,2025/03/04|16:45:00,0,2,kitchen,7d|3,2,1,
        newChore.mName = buffer.substr(0, buffer.find(',') - 1);
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
        //newChore.mDateAndTime = buffer.substr(0,buffer.find(',') - 1); 
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
        if (!(buffer[0] - 'a')) // buffer[0] = 0
            newChore.mCompletionStatus = false;
        else
            newChore.mCompletionStatus = true;
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);

        switch(buffer[0])
        {
            case '0': newChore.mPriority = Priority::LOW;
            case '1': newChore.mPriority = Priority::MEDIUM;
            case '2': newChore.mPriority = Priority::HIGH;
            case '3': newChore.mPriority = Priority::IMMINENT;
        }
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
        newChore.mLocation = buffer.substr(0,buffer.find(',') - 1);
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
        // newChore.mRecurrenceInterval = buffer.substr(0,buffer.find(',') - 1);
        buffer = buffer.substr(buffer.find(',') + 1, buffer.size() - buffer.find(',') - 1);
        buffer.erase(0,1); // deletes '|'
        for (uint64_t i : ids)
        {
            newChore.addAvailability(i, static_cast<Availability>(buffer.front())); // think about 2 digit availability later
        }
        getline(infile, buffer);
        house.addChore(std::move(newChore));
    }

    infile.close();

    return householdPtr;
}

std::shared_ptr<Household> HouseholdManager::makeNewHousehold(User& firstMemberUser, Household&& householdInfo) {
    auto householdPtr{ std::make_shared<Household>(householdInfo) };

    householdPtr->handleUserJoining(firstMemberUser);
    firstMemberUser.addHousehold(householdPtr);
    
    return householdPtr;
}
