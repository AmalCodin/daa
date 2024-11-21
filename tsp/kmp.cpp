#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to preprocess the pattern and create the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string &pattern, vector<int> &lps) {
    int m = pattern.length();
    int length = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;      // LPS[0] is always 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            // mismatch after length matches
            if (length != 0) {
                // Do not increment i, we use the previously computed LPS to avoid redundant checks
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm for searching pattern in text
void KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    // Create LPS array for the pattern
    vector<int> lps(m, 0);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            // mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    KMPSearch(text, pattern);

    return 0;
}
