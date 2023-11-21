#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std; 

class CaesarCypher : public Crypto {
private:
    int key;
    string EncryptDecrypt(const string text, bool encrypt) {
        if (!encrypt)
            key = -key;
        string changedText = "";
        for (char ch : text) {
            char base = isupper(ch) ? 'A' : 'a';
            if (isalpha(ch)) {
                char encodedChar = ((ch - base + key) % 26) + base;
                changedText += encodedChar;
            }
            else {
                changedText += ch;
            }
        }
        return changedText;
    }

public:
    CaesarCypher(int cipherKey) : key(cipherKey) {}
    ~CaesarCypher() {}

    string Encrypt(const string& input) {
        return EncryptDecrypt(input, true);
    }

    string Decrypt(const string& input) {
        return EncryptDecrypt(input, false);
    }
};
