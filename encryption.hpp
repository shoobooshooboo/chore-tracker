#pragma once
#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <cctype>
#include <string>
#include <fstream>

namespace Encryption {
    [[nodiscard]] constexpr char shiftDown(char c) noexcept;
    [[nodiscard]] constexpr char shiftUp(char c) noexcept;

    [[nodiscard]] constexpr char shiftEncrypt(char c, char key) noexcept;
    [[nodiscard]] constexpr char shiftDecrypt(char c, char key) noexcept;

    [[nodiscard]] std::string encrypt(std::string password, const std::string& name);
    [[nodiscard]] std::string decrypt(std::string password, const std::string& name);

    void encryptFile();
    void decryptFile();
}

#endif