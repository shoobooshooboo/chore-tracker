#include "user_manager.hpp"

namespace UserManager {
    container_t::const_iterator findLoadedUser(const uint64_t userID) {
        return std::ranges::find_if(loadedUsers, 
            [userID](const User& loadedUser){ return userID == loadedUser.getID(); }, 
            std::shared_ptr<User>::operator*
        );
    }

    // assumes user exists
    container_t::const_iterator loadUser(const uint64_t userID) {
        auto it{findLoadedUser(userID)};
        if (it == loadedUsers.cend()) { // user is not yet loaded
            std::ifstream infile("test.csv");
            
            uint64_t testID;
            while (infile.good()) { 
                infile >> testID;
                if (testID == userID) // break when line matching usedID is found  
                    break; 
                infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            for (int i{0}; i < 3; ++i) { // chop comma after userID, and discard "username, password,"
                infile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            }
            std::string name;
            std::getline(infile, name, ',');
            loadedUsers.push_back(std::make_shared<User>(testID, std::move(name)));
            
            it = std::prev(loadedUsers.cend());
        } 

        return it;
    }

    void storeUser(const User& user) {
        // TODO
    }
}