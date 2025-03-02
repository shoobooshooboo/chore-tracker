#include "app.hpp"


// DEMO MAIN
// All of the user IO here to be replaced with actual GUI interaction
int main(void) {

    char input{'\0'};
    while (input < '1' || input > '2') {
        std::cout << "1. Log In\n2. Sign Up\n";
        std::cin >> input;
    }
    switch (input) {
        case '1':
            App::logIn();
            break;
        case '2':
            App::signUp();
            break;
    }
    
    App::startup();

    // TODO put some stuff here 
    /** features to show
     * making a household 
     * inviting users by ID (TODO)
     * adding chores to a household
     * chore display: all, filter, search, sort
     * */ 

}