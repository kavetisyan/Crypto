#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class Vigenere : public Crypto {
private:
    string key;
public:
    Vigenere(string key) : key(key) {}
    ~Vigenere() {}
    string Encrypt(const string& text) {
        string newText = "";
        for (int i = 0; i < text.length(); ++i) {
            char letter = text[i];
            char keyLetter = key[i % key.length()];
            if (isalpha(letter)) {
                char newLetter = 'A' + (toupper(letter) + toupper(keyLetter) - 2 * 'A') % 26;
                if (islower(letter)) {
                    newLetter = tolower(newLetter);
                }
                newText += newLetter;
            }
            else {
                newText += letter;
            }
        }
        return newText;
    }
    string Decrypt(const string& text) {
        string newText = "";
        for (int i = 0; i < text.length(); ++i) {
            char letter = text[i];
            char keyLetter = key[i % key.length()];
            if (isalpha(letter)) {
                char newChar = 'A' + (toupper(letter) - toupper(keyLetter) + 26) % 26;
                if (islower(letter)) {
                    newChar = tolower(newChar);
                }
                newText += newChar;
            }
            else {
                newText += letter;
            }
        }
        return newText;
    }
};
