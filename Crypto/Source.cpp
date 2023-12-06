#include <iostream>
#include <string>
#include <vector>
#include "Crypto.h"
#include "VigenereModificated.h"
#include "Vigenere.h"
#include "CaesarCypher.h"
#include "SimpleSubstitution.h"
#include "RLE.h"
#include "EuclideanAlgorithms.h"
#include "Huffman.h"
#include "Feistel.h"
using namespace std;

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
    #pragma region SimpleSubstitution
    string substitutionKey = "XAZYBCEDFGKWRHLMNOPQJSTUVI";
    SimpleSubstitution crypto(substitutionKey);

    string plaintext = "Hello, World!";
    string ciphertext = crypto.Encrypt(plaintext);
    string decryptedText = crypto.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Simple Substitution: " << ciphertext << endl;
    cout << "Decrypted Text with Simple Substitution: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region RLE
    RLE rleCrypto;
    plaintext = "1110011110001";
    ciphertext = rleCrypto.Encrypt(plaintext);
    decryptedText = rleCrypto.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with RLE: " << ciphertext << endl;
    cout << "Decrypted Text with RLE: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region CaesarCypher
    int caesarKey = 3;
    CaesarCypher caesarCypher(caesarKey);
    plaintext = "Hello";
    ciphertext = caesarCypher.Encrypt(plaintext);
    decryptedText = caesarCypher.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Caesar Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Caesar Cypher: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region Vigenere
    string vigenerKey = "vigenere";
    Vigenere vigenereCypher(vigenerKey);
    plaintext = "Hello World!";
    ciphertext = vigenereCypher.Encrypt(plaintext);
    decryptedText = vigenereCypher.Decrypt(ciphertext);
   
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Vigenere Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Vigenere Cypher: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region VigenereModificated
    string vigenerModificatedKey = "A";
    VigenereModificated vigenereModificatedCypher(vigenerModificatedKey);
    plaintext = "Hello World!";
    ciphertext = vigenereModificatedCypher.Encrypt(plaintext);
    decryptedText = vigenereModificatedCypher.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Vigenere Modificated Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Vigenere Modificated Cypher: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region Huffman
    Huffman huffman;
    plaintext = "Hello World!";
    ciphertext = huffman.Encrypt(plaintext);
    decryptedText = huffman.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Huffman Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Huffman Cypher: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region Feistel
    string key = "secret";
    Feistel feistel(key);
    plaintext = "Hello World!";
    ciphertext = feistel.Encrypt(plaintext);
    decryptedText = feistel.Decrypt(ciphertext);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext with Feistel Cypher: " << ciphertext << endl;
    cout << "Decrypted Text with Feistel Cypher: " << decryptedText << endl;
    cout << endl;
    #pragma endregion

    #pragma region TransposeMatrix
    vector<vector<int>> original = { {1, 1, 0}, {1, 0, 0}, {0, 1, 1} };
    cout << "Original Matrix:" << endl;
    printMatrix(original);

    vector<vector<int>> transposed = transposeMatrix(original);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed);
    cout << endl;
    #pragma endregion

    #pragma region FindMissingNumber
    vector<int> array = { 5, 2, 8, 4, 9, 1, 3, 6 };
    printArray(array);
    cout << "Missing number in array: " << findMissingNumber(array) << endl;
    cout << endl;
    #pragma endregion

    #pragma region EuclideanAlgorithms
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
    #pragma endregion
    return 0;
}
