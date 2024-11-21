#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to find the minimum cost of matrix chain multiplication
int matrixChainRecursive(const vector<int>& dimensions, int i, int j) {
    if (i == j) // Base case: Single matrix requires no multiplication
        return 0;

    int minCost = INT_MAX;

    // Try placing the parenthesis at every possible position and find the minimum cost
    for (int k = i; k < j; ++k) {
        int cost = matrixChainRecursive(dimensions, i, k) +
                   matrixChainRecursive(dimensions, k + 1, j) +
                   dimensions[i - 1] * dimensions[k] * dimensions[j];

        minCost = min(minCost, cost);
    }

    return minCost;
}

int main() {
    // Example dimensions of matrices: A1 (10x20), A2 (20x30), A3 (30x40), A4 (40x30)
    vector<int> dimensions = {10, 20, 30, 40, 30};

    // Number of matrices is dimensions.size() - 1
    int n = dimensions.size() - 1;

    // Find the minimum number of scalar multiplications
    int minCost = matrixChainRecursive(dimensions, 1, n);

    // Print the result
    cout << "Minimum number of scalar multiplications: " << minCost << endl;

    return 0;
}
