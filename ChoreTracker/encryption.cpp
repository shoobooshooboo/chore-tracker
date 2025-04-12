#include "encryption.hpp"

constexpr char Encryption::keyToShiftCount(char key) noexcept {
    // set key to represent the appropriate integer number of shifts to perform 
    if (std::islower(key)) {
        key -= ('a' - 1); // 1-26 shifts possible
    } else if (std::isupper(key)) {
        key -= ('A' - 1); // 1-26 shifts possible
    } else if (std::isdigit(key)) {
        key -= '0'; // 0-9 shifts possible
    }
    return key;
}

constexpr char Encryption::shiftDown(char c) noexcept {
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

constexpr char Encryption::shiftUp(char c) noexcept {
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
constexpr char Encryption::shiftEncrypt(char c, char key) noexcept {
    key = keyToShiftCount(key);

    while (key-- > 0) {
        c = shiftDown(c);
    }
    return c;
}



constexpr char Encryption::shiftDecrypt(char c, char key) noexcept {
    key = keyToShiftCount(key);

    while (key-- > 0) {
        c = shiftUp(c);
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