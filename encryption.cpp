#include "encryption.hpp"

// takes in a password character and a username character and returns the encrypted version
char Encryption::shiftEncrypt(char c, char key)
{
    if (key >= '0' and key <= '9') // number
    {
        while (key > '0')
        {
            if (c == 'A')
                c = 'Z';
            else if (c == 'a')
                c = 'z';
            else if (c == '0')
                c = '9';
            else
                c = static_cast<char>(c - 1);

            key = static_cast<char>(key - 1);
        }
    }
    else // letter
    {
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key > static_cast<char>('A' - 1))
        {
            if (c == 'A')
                c = 'Z';
            else if (c == 'a')
                c = 'z';
            else if (c == '0')
                c = '9';
            else
                c = static_cast<char>(c - 1);

            key = static_cast<char>(key - 1);
        }
    }
    return c;
}

char Encryption::shiftDecrypt(char c, char key)
{
    if (key >= '0' and key <= '9') // number
    {
        while (key > '0')
        {
            if (c == 'Z')
                c = 'A';
            else if (c == 'z')
                c = 'a';
            else if (c == '9')
                c = '0';
            else
                c = static_cast<char>(c + 1);

            key = static_cast<char>(key - 1);
        }
    }
    else
    {
        key = toupper(key); // guard to make sure it's uppercase for checks
        while (key > static_cast<char>('A' - 1))
        {
            if (c == 'Z')
                c = 'A';
            else if (c == 'z')
                c = 'a';
            else if (c == '9')
                c = '0';
            else
                c = static_cast<char>(c + 1);

            key = static_cast<char>(key - 1);
        }
    }
    return c;
}


std::string Encryption::encrypt(std::string password, std::string name)
{
    if (password.size() <= name.size()) // loop can just loop, no extra checks needed
    {
        for (int i = 0; i < password.size(); i++)
        {
            password[i] = shiftEncrypt(password[i], name[i]);
        }
    }
    else // needs to check since it has to loop around the password multiple times
    {
        for (int i = 0; i < password.size(); i++)
        {
            if (i >= name.size()) // without this it would index out of bounds on password
            {
                int j = i;
                do
                {
                    j -= name.size();
                } while (j >= name.size());
                password[i] = shiftEncrypt(password[i], name[j]);
            }
            else
                password[i] = shiftEncrypt(password[i], name[i]);

        }

    }
    return password;
}

std::string Encryption::decrypt(std::string password, std::string name)
{
    if (password.size() <= name.size()) // loop can just loop, no extra checks needed
    {
        for (int i = 0; i < password.size(); i++)
        {
            password[i] = shiftDecrypt(password[i], name[i]);
        }
    }
    else // needs to check since it has to loop around the password multiple times
    {
        for (int i = 0; i < password.size(); i++)
        {
            if (i >= name.size()) // without this it would index out of bounds on password
            {
                int j = i;
                do
                {
                    j -= name.size();
                } while (j >= name.size());
                password[i] = shiftDecrypt(password[i], name[j]);
            }
            else
                password[i] = shiftDecrypt(password[i], name[i]);

        }

    }
    return password;
}

void encryptFile()
{
    std::ifstream infile("file.csv");
}
void decryptFile();