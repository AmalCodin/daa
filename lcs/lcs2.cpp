#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

string LCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // End timing
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Reconstruct the LCS
    int index = L[m][n];
    string lcs(index, '\0'); // Initialize the LCS string with null characters

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output results
    cout << "Length of LCS: " << L[m][n] << endl;
    cout << "LCS: " << lcs << endl;
    cout << "Time taken (ms): " << duration << endl;

    return lcs;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    LCS(X, Y);

    return 0;
}
