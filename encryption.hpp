#pragma once
#include <filesystem>
#include <string>
#include <fstream>

std::string encrypt(std::string name, std::string password);
std::string decrypt(std::string name, std::string password);

void encryptFile();
void decryptFile();