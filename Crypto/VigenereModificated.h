#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class VigenereModificated : public Crypto {
private:
    string key;
    VigenereModificated() = delete;
public:
    VigenereModificated(string key) : key(key) {}
    ~VigenereModificated() {}
    string Encrypt(const string& text) {
        string newText = "";
        for (int i = 0; i < text.length(); ++i) {
            char letter = text[i];
            char keyLetter = key[i % key.length()];
            newText += (letter + keyLetter) % 256;
        }
        return newText;
    }
    string Decrypt(const string& text) {
        string newText = "";
        for (int i = 0; i < text.length(); ++i) {
            char letter = text[i];
            char keyLetter = key[i % key.length()];
            newText += (letter - keyLetter + 256) % 256;
        }
        return newText;
    }
};
