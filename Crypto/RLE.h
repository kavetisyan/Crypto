#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class RLE : public Crypto {
public:
    string Encrypt(const string& plaintext) override {
        string encoded;
        int count = 1;
        for (int i = 1; i <= plaintext.size(); ++i) {
            if (i < plaintext.size() && plaintext[i] == plaintext[i - 1]) {
                count++;
            }
            else {
                encoded += plaintext[i - 1] + to_string(count);
                count = 1;
            }
        }
        return encoded;
    }

    string Decrypt(const string& ciphertext) override {
        string decoded;
        for (int i = 0; i < ciphertext.size(); i += 2) {
            char character = ciphertext[i];
            int count = ciphertext[i + 1] - '0';
            for (int j = 0; j < count; ++j) {
                decoded += character;
            }
        }
        return decoded;
    }
};
