#pragma once
#include <string>
using namespace std;

class Crypto {
public:
    virtual string Encrypt(const string& plaintext) = 0;
    virtual string Decrypt(const string& ciphertext) = 0;
};
