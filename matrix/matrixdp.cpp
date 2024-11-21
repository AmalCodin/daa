#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function to find the minimum cost of matrix chain multiplication
int matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Length of the chain (from 2 to n matrices)
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1]; // Minimum cost to multiply all matrices
}

int main() {
    // Example dimensions of matrices: A1 (10x20), A2 (20x30), A3 (30x40), A4 (40x30)
    vector<int> dimensions = {10, 20, 30, 40, 30};

    // Find the minimum number of scalar multiplications
    int minCost = matrixChainMultiplication(dimensions);

    // Print the result
    cout << "Minimum number of scalar multiplications: " << minCost << endl;

    return 0;
}
