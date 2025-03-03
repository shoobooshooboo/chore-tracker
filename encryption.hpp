#pragma once
#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <filesystem>
#include <string>
#include <fstream>

namespace Encryption {
    [[nodiscard]] char shiftDown(char c) noexcept;
    [[nodiscard]] char shiftUp(char c) noexcept;

    [[nodiscard]] char shiftEncrypt(char c, char key) noexcept;
    [[nodiscard]] char shiftDecrypt(char c, char key) noexcept;

    [[nodiscard]] std::string encrypt(std::string password, const std::string& name);
    [[nodiscard]] std::string decrypt(std::string password, const std::string& name);

    void encryptFile();
    void decryptFile();
}

#endif