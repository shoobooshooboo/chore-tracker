#include "encryption.hpp"

char Encryption::shiftDown(char c) noexcept {
    switch (c) {
        case 'A': 
            return 'Z';
        case 'a': 
            return 'z';
        case '0': 
            return '9';
        default:
            return c - 1;
    }
}

char Encryption::shiftUp(char c) noexcept {
    switch (c) {
        case 'Z': 
            return 'A';
        case 'z': 
            return 'a';
        case '9': 
            return '0';
        default:
            return c + 1;
    }
}

// takes in a password character and a username character and returns the encrypted version
char Encryption::shiftEncrypt(char c, char key) noexcept {
    if (std::isdigit(key)) { 
        while (key > '0') {
            c = shiftDown(c);
            --key;
        }
    } else { // letter
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key >= 'A') {
            c = shiftDown(c);
            --key;
        }
    }
    return c;
}

char Encryption::shiftDecrypt(char c, char key) noexcept {
    if (std::isdigit(key)) { 
        while (key > '0') {
            c = shiftUp(c);
           --key;
        }
    } else {
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key >= 'A') {
            c = shiftUp(c);
            --key;
        }
    }
    return c;
}

std::string Encryption::encrypt(std::string password, const std::string& name) {
    for (size_t i{0}; i < password.size(); ++i) {
        password[i] = shiftEncrypt(password[i], name[i % name.size()]);
    }
    return password;
}

std::string Encryption::decrypt(std::string password, const std::string& name) {
    for (size_t i{0}; i < password.size(); ++i) {
        password[i] = shiftDecrypt(password[i], name[i % name.size()]);
    }
    return password;
}

void encryptFile() {
    std::ifstream infile("file.csv");
}

void decryptFile();