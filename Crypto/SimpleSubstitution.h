#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class SimpleSubstitution : public Crypto {
private:
    string substitutionKey;

    string EncryptDecrypt(const string text, bool encrypt) {
        string changedText = text;
        for (char& ch : changedText) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                char encryptedChar;
                if (encrypt) {
                    int index = ch - base;
                    encryptedChar = islower(ch) ? tolower(substitutionKey[index]) : toupper(substitutionKey[index]);
                }
                else {
                    int index = base + substitutionKey.find(toupper(ch));
                    encryptedChar = islower(ch) ? tolower(char(index)) : toupper(char(index));
                }
                ch = encryptedChar;
            }
        }
        return changedText;
    }

public:
    SimpleSubstitution(const string& key) : substitutionKey(key) {}
    ~SimpleSubstitution() {}

    string Encrypt(const string& plaintext) override {
        return EncryptDecrypt(plaintext, true);
    }

    string Decrypt(const string& ciphertext) override {
        return EncryptDecrypt(ciphertext, false);
    }
};
