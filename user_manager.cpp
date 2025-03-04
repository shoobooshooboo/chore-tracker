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
        if (it == loadedUsers.cend()) // user is not yet loaded
        {
            std::ifstream infile("test.csv");
            std::string buffer, name;
            uint64_t testID;

            while (true) {
                infile >> std::ws >> testID;
                if (testID == userID) {
                    std::getline(infile, buffer);
                    break;
                }
                infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < 3; i++)
            {
                infile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            }
            std::getline(infile, name, ',');

            User userToLoad(testID, std::move(name));

            loadedUsers.push_back(std::make_shared<User>(userToLoad));
            
            it = std::prev(loadedUsers.cend());
        } 

        return it;
    }
}