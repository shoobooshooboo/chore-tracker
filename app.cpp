#include "app.hpp"

void App::startup(void) {

    // restructure this bit as necessary to be able to get that data put in
    UserManager::loadedUsers.push_back(
        std::make_shared<User>(
            User {/*data from file, line selected as a result of login*/}
        ) 
    );

    while (1/*placeholder condition, should read until end of line (ie until all householdIDs are read)*/) {
        // load household loads & links all users automatically, including localUser
        HouseholdManager::loadHousehold(0/*placeholder, should be householdID*/);

    }

}