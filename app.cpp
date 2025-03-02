#include "app.hpp"

bool App::logIn(void) {
    // THIS IS TEMPORARY - REPLACE WITH UI THING
    std::cout << "Enter Username: ";
    std::string username;
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::string password;
    std::cin >> password;

    bool matchFound{false};
    // TODO search file for a user matching username && password
    
    if (matchFound) {
        User localUser{/*placeholder data from file*/};
        UserManager::loadedUsers.push_back(std::make_shared<User>(localUser));
    }

    return matchFound;
}

void App::signUp(void) {
    // THIS IS TEMPORARY - REPLACE WITH UI THING

    do {
        // TODO get a username/password
    } while (0/* TODO condition is while usename/password invalid */);

    // TODO get any other user information needed at signup

    UserManager::loadedUsers.push_back(std::make_shared<User>(User(/**/)));
}

void App::startup(void) {

    // restructure this bit as necessary to be able to get that data put in
    UserManager::loadedUsers.push_back(
        std::make_shared<User>(
            User {/*data from file, line selected as a result of login*/}
        ) 
    );

    while (1/*placeholder condition, should read until end of line (ie until all householdIDs are read)*/) {

        // loadHousehold loads & links all users automatically, including localUser
        HouseholdManager::loadHousehold(0/*placeholder, should be householdID*/);

    }

}