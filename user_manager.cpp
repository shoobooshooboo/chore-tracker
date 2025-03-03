#include "user_manager.hpp"

namespace UserManager {

    container_t::const_iterator findLoadedUser(const uint64_t userID) {
        return std::ranges::find_if(loadedUsers, 
            [userID](const User& loadedUser){ return userID == loadedUser.getID(); }, 
            std::shared_ptr<User>::operator*
        );
    }

    container_t::const_iterator loadUser(const uint64_t userID) {
        auto it{findLoadedUser(userID)};

        if (it == loadedUsers.cend()) 
        {
            User userToLoad;
            // TODO 
            // load the new user and push to the back
            // if we decide to maintain ordering by ID in the file, do a binary search
            // otherwise linear also would probably be fine
            // use below to skip lines after parsing the ID token if not a match
            // <filestream here>.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            loadedUsers.push_back(std::make_shared<User>(userToLoad));
            
            it = std::prev(loadedUsers.cend());
        } 

        return it;
    }
}