#include "user_manager.hpp"

namespace UserManager {

container_t::iterator findLoadedUser(const uint64_t userID) {
    return std::ranges::find_if(loadedUsers, 
        [userID](const User& loadedUser){ return userID == loadedUser.getID(); }
    );
}

User* loadUser(const uint64_t userID) {
    auto it{findLoadedUser(userID)};
    if (it == loadedUsers.cend()) { // user is not yet loaded
        std::ifstream infile(userFile);
        
        uint64_t testID;
        while (infile.good()) { 
            infile >> testID;
            if (testID == userID) // break when line matching usedID is found  
                break; 
            infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        // ignore up to the user's "first last" name
        infile.ignore(std::numeric_limits<std::streamsize>::max(), '|');

        std::string name;
        std::getline(infile, name);
        loadedUsers.emplace_back(testID, std::move(name));
        
        it = std::prev(loadedUsers.end());
    } 

    return std::addressof(*it);
}

void createUserToFile(const User& user, const std::string& username, const std::string& password, const uint64_t firstHousehold) {
    std::ofstream(userFile, std::ios::app) << std::format("{},{},{}|{},{}\n", user.getID(), username, password, user.getName(), firstHousehold);
}

}