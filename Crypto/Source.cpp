#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Crypto {
public:
    virtual string Encrypt(const string& plaintext) = 0;
    virtual string Decrypt(const string& ciphertext) = 0;
};

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

    string Encrypt(const string& input) {
        return EncryptDecrypt(input, true);
    }

    string Decrypt(const string& input) {
        return EncryptDecrypt(input, false);
    }
};

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

    string Encrypt(const string& plaintext) override {
        return EncryptDecrypt(plaintext, true);
    }

    string Decrypt(const string& ciphertext) override {
        return EncryptDecrypt(ciphertext, false);
    }
};

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

class EuclideanAlgorithms {
public:
    int getDivisorWithSubtraction(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (a != b) {
            if (a > b) {
                a -= b;
            }
            else {
                b -= a;
            }
        }
        return a;
    }
    int getDivisorWithDivision(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int getSmallestMultiple(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        int divisor = getDivisorWithDivision(a, b);
        int multiple = (a * b) / divisor;
        return multiple;
    }
};

vector<vector<int>> transposeMatrix(const vector<vector<int>>& input) {
    int n = input.size();
    vector<vector<int>> transposed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[i][j] = input[j][i];
        }
    }
    return transposed;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int findMissingNumber(vector<int>& numbers) {
    int n = numbers.size() + 1;
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for (int num : numbers) {
        arraySum += num;
    }
    int missingNumber = totalSum - arraySum;
    return missingNumber;
}

void printArray(const vector<int>& array) {
    for (const int& num : array) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    string substitutionKey = "XAZYBCEDFGKWRHLMNOPQJSTUVI";
    SimpleSubstitution crypto(substitutionKey);

    string plaintext = "Hello, World!";
    string ciphertext = crypto.Encrypt(plaintext);
    string decryptedText = crypto.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Simple Substitution: " << ciphertext << endl;
    cout << "Decrypted Text with Simple Substitution: " << decryptedText << endl;
    cout << endl;

    RLE rleCrypto;
    plaintext = "1110011110001";
    ciphertext = rleCrypto.Encrypt(plaintext);
    decryptedText = rleCrypto.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with RLE: " << ciphertext << endl;
    cout << "Decrypted Text with RLE: " << decryptedText << endl;
    cout << endl;

    int caesarKey = 3;
    CaesarCypher caesarCypher(caesarKey);
    plaintext = "Hello";
    ciphertext = caesarCypher.Encrypt(plaintext);
    decryptedText = caesarCypher.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Caesar Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Caesar Cypher: " << decryptedText << endl;
    cout << endl;

    vector<vector<int>> original = { {1, 1, 0}, {1, 0, 0}, {0, 1, 1} };
    cout << "Original Matrix:" << endl;
    printMatrix(original);

    vector<vector<int>> transposed = transposeMatrix(original);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed);
    cout << endl;

    vector<int> array = { 5, 2, 8, 4, 9, 1, 3, 6 };
    printArray(array);
    cout << "Missing number in array: " << findMissingNumber(array) << endl;
    cout << endl;

    int num1, num2;
    EuclideanAlgorithms ea;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int divisor1 = ea.getDivisorWithSubtraction(num1, num2);
    int divisor2 = ea.getDivisorWithDivision(num1, num2);
    int multiple = ea.getSmallestMultiple(num1, num2);

    cout << "Greatest Divisor With Subtraction: " << divisor1 << endl;
    cout << "Greatest Divisor With Division: " << divisor2 << endl;
    cout << "Smallest Multiple: " << multiple << endl;
    

    return 0;
}
