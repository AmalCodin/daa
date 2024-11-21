#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// A tree node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Min-heap based on frequency
    }
};

// Function to build the Huffman Tree
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until the tree is complete
    while (pq.size() > 1) {
        // Remove the two nodes with the smallest frequency
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    return pq.top(); // The root of the Huffman Tree
}

// Function to generate Huffman Codes
void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

// Function to print the Huffman Codes
void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Main function
int main() {
    string text = "huffman coding example";

    // Count the frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Build the Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Generate and print Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    printHuffmanCodes(huffmanCodes);

    // Optional: Print the encoded string
    cout << "\nEncoded String: ";
    for (char ch : text) {
        cout << huffmanCodes[ch];
    }
    cout << endl;

    return 0;
}
