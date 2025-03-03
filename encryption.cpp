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
            return static_cast<char>(c - 1);
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
            return static_cast<char>(c + 1);
    }
}

// takes in a password character and a username character and returns the encrypted version
char Encryption::shiftEncrypt(char c, char key) noexcept {
    if (key >= '0' && key <= '9') { // number
        while (key > '0') {
            c = shiftDown(c);
            key = static_cast<char>(key - 1);
        }
    } else { // letter
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key > static_cast<char>('A' - 1)) {
            c = shiftDown(c);
            key = static_cast<char>(key - 1);
        }
    }
    return c;
}

char Encryption::shiftDecrypt(char c, char key) {
    if (key >= '0' && key <= '9') { // number
        while (key > '0') {
            c = shiftUp(c);
            key = static_cast<char>(key - 1);
        }
    } else {
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key > static_cast<char>('A' - 1)) {
            c = shiftUp(c);
            key = static_cast<char>(key - 1);
        }
    }
    return c;
}

std::string Encryption::encrypt(std::string password, const std::string& name) {
    if (password.size() <= name.size()) { // loop can just loop, no extra checks needed
        for (size_t i{0}; i < password.size(); ++i) {
            password[i] = shiftEncrypt(password[i], name[i]);
        }
    } else { // needs to check since it has to loop around the password multiple times
        for (size_t i{0}; i < password.size(); ++i) {
            if (i >= name.size()) { // without this it would index out of bounds on password
                size_t j{i};
                do {
                    j -= name.size();
                } while (j >= name.size());
                password[i] = shiftEncrypt(password[i], name[j]);
            }
            else password[i] = shiftEncrypt(password[i], name[i]);
        }
    }
    return password;
}

std::string Encryption::decrypt(std::string password, const std::string& name) {
    if (password.size() <= name.size()) { // loop can just loop, no extra checks needed
        for (size_t i{0}; i < password.size(); ++i) {
            password[i] = shiftDecrypt(password[i], name[i]);
        }
    } else { // needs to check since it has to loop around the password multiple times
        for (size_t i{0}; i < password.size(); ++i) {
            if (i >= name.size()) { // without this it would index out of bounds on password
                size_t j{i};
                do {
                    j -= name.size();
                } while (j >= name.size());
                password[i] = shiftDecrypt(password[i], name[j]);
            }
            else password[i] = shiftDecrypt(password[i], name[i]);
        }
    }
    return password;
}

void encryptFile() {
    std::ifstream infile("file.csv");
}

void decryptFile();