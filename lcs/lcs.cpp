#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the LCS using dynamic programming
int longestCommonSubsequence(const string& str1, const string& str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n]; // The length of the LCS
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int lcsLength = longestCommonSubsequence(str1, str2);

    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
