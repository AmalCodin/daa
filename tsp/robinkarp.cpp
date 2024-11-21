#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to compute the hash of a string
int hashValue(const string &str, int prime, int base) {
    int hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash = (hash * base + str[i]) % prime;
    }
    return hash;
}

// Rabin-Karp string matching algorithm
vector<int> rabinKarp(const string &text, const string &pattern, int prime, int base) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = hashValue(pattern, prime, base);
    int textHash = hashValue(text.substr(0, m), prime, base);
    int h = pow(base, m - 1) - 1;  // Precomputed value for rolling hash
    vector<int> result;

    for (int i = 0; i <= n - m; i++) {
        // If hash values match, check the actual substring
        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern) {
                result.push_back(i);  // Match found at index i
            }
        }

        // Update the hash value for the next window using rolling hash
        if (i < n - m) {
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0) {
                textHash += prime;  // Handle negative hash values
            }
        }
    }
    return result;
}

int main() {
    string text, pattern;
    int prime = 101;  // A large prime number for hashing
    int base = 256;   // Base value for hashing (assuming ASCII characters)

    // Taking input for text and pattern
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;

    // Find the occurrences of the pattern in the text
    vector<int> result = rabinKarp(text, pattern, prime, base);

    if (!result.empty()) {
        cout << "Pattern found at positions: ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
