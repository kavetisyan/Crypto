#include <iostream>
#include <string>
#include <bitset>
#include "Crypto.h"
using namespace std;

class Feistel : public Crypto {
public:
    string key;
    Feistel(string key) : key(key) {}
    ~Feistel() {}

    string Encrypt(const string& plaintext) override {
        return EncryptDecrypt(plaintext, true);
    }

    string Decrypt(const string& ciphertext) override {
        return EncryptDecrypt(ciphertext, false);
    }

private:
    string xorStrings(const string& a, const string& b) {
        string result;
        for (size_t i = 0; i < a.length(); ++i) {
            result += static_cast<char>(a[i] ^ b[i]);
        }
        return result;
    }

    void feistelRound(string& left, const string& right){
        string result = xorStrings(right, key);
        left = xorStrings(left, result);
    }

    string EncryptDecrypt(const string& input, bool encrypt) {
        string block = input;

        size_t blockSize = block.length() / 2;
        string left = block.substr(0, blockSize);
        string right = block.substr(blockSize);

        int numRounds = 5;
        for (int round = 0; round < numRounds; ++round) {
            if (encrypt) {
                feistelRound(left, right);
            }
            else {
                feistelRound(right, left);
            }
        }

        return right + left;
    }
};