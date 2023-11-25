#include <iostream>
#include <unordered_map>
#include <vector>
#include "Crypto.h"
#include <algorithm>
using namespace std;

class Node {
public:
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

    bool operator<(const Node& other) const {
        return frequency > other.frequency;
    }
};

class Huffman : public Crypto {
private:
    unordered_map<char, string> codes;
    Node* root;
    
    void buildTree(const unordered_map<char, int>& freq) {
        vector<Node*> nodes;
        for (const auto& pair : freq) {
            nodes.push_back(new Node(pair.first, pair.second));
        }
        while (nodes.size() > 1) {
            sort(nodes.begin(), nodes.end());

            Node* left = nodes.back(); nodes.pop_back();
            Node* right = nodes.back(); nodes.pop_back();

            Node* internalNode = new Node('$', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;

            nodes.push_back(internalNode);
        }
        root = nodes.front();
    }

    void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
        if (root == nullptr) {
            return;
        }
        if (root->data != '$') {
            codes[root->data] = code;
        }
        generateCodes(root->left, code + "0", codes);
        generateCodes(root->right, code + "1", codes);
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    Huffman() : root(nullptr) {}
    ~Huffman() { deleteTree(root); }

    string Encrypt(const string& text) {
        string encodedText = ""; 
        
        unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }
        buildTree(freq);
        generateCodes(root, "", codes);
        
        for (char c : text) {
            encodedText += codes[c];
        }
        return encodedText;
    }

    string Decrypt(const string& text) {
        string decodedText = "";
        Node* current = root;
        for (char bit : text) {
            if (bit == '0') {
                current = current ? current->left : nullptr;
            }
            else {
                current = current ? current->right : nullptr;
            }
            if (current != nullptr && current->left == nullptr && current->right == nullptr) {
                decodedText += current->data;
                current = root; 
            }
        }
        return decodedText;
    }
};
