#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int n, vector<vector<int>>& dist) {
    // DP table to store the minimum cost for a subset of cities ending at a specific city
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    
    // Starting from the first city (0), cost is 0
    dp[1][0] = 0;

    // Iterate over all subsets of cities
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            // If the city u is in the current subset (mask)
            if (mask & (1 << u)) {
                for (int v = 0; v < n; ++v) {
                    // If city v is not in the current subset, we try to go from city u to v
                    if (!(mask & (1 << v))) {
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    // The answer is the minimum cost to visit all cities and return to the starting city
    int ans = INT_MAX;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][0]);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    int result = tsp(n, dist);
    cout << "The minimum cost of the tour is: " << result << endl;

    return 0;
}
