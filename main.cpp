#include "app.hpp"


// DEMO MAIN
// All of the user IO here to be replaced with actual GUI interaction
int main(void) {

    char input;
    do {
        std::cout << "1. Log In\n2. Sign Up\n";
        std::cin >> input;
    } while (input < '1' || input > '2');

    switch (input) {
        case '1':
            App::logIn();
            break;
        case '2':
            App::signUp();
            break;
    }
    
    App::startup();

}