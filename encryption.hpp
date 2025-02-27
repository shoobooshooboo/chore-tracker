#pragma once
#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <filesystem>
#include <string>
#include <fstream>

namespace Encryption{
    std::string encrypt(std::string name, std::string password);
    std::string decrypt(std::string name, std::string password);

    void encryptFile();
    void decryptFile();
}

#endif