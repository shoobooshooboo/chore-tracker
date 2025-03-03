#include "app.hpp"

bool App::logIn(void) {
    // THIS IS TEMPORARY - REPLACE WITH GUI THING
    std::print("Enter Username: ");
    std::string username;
    std::cin >> username;
    std::print("Enter Password: ");
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
    // MOST OF THIS IS TEMPORARY - REPLACE WITH GUI THING

    constexpr static auto validCheck {[](const std::string& str){
        return std::ranges::find_if_not(str, static_cast<int(*)(int)>(std::isalnum)) != str.cend();
    }};

    std::string username, password;
    do {
        std::print("Sign Up\nEnter Username: ");
        std::cin >> username;
        std::print("Enter Password: ");
        std::cin >> password;
    } while (!validCheck(username) || !validCheck(password));

    std::println("Enter your name below: ");
    std::string name;
    std::cin >> name;

    // TODO query for next available unique ID (maybe another reason to enforce ordering in users.csv)

    // TODO write all of the needed info to userfile

    // logs in automatically
    UserManager::loadedUsers.push_back(std::make_shared<User>(User(/*PLACEHOLDERS!!!*/)));

    assert(UserManager::loadedUsers.size() == 1);

    // generates the user's personal household
    HouseholdManager::makeNewHousehold(UserManager::loadedUsers.cbegin(), Household{std::format("{}'s To-Do", name)});
}

void App::startup(void) {
    assert(UserManager::loadedUsers.size() == 1);

    while (1/*placeholder: while household IDs are left in the line of the userFile corresponding with loadedUsers.front()'s ID*/) {

        // loadHousehold loads & links all users automatically, including localUser
        // just need to call that and things get taken care of
        HouseholdManager::loadHousehold(0/*placeholder, should be householdID*/);
    }

}