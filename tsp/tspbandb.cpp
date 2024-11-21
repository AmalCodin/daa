#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> dist;

// Function to calculate the minimum cost of visiting all cities
int bound(int currPos, vector<int>& path, int count, int cost) {
    if (count == n) {
        return cost + dist[currPos][0]; // Return to the starting city
    }

    // Lower bound calculation: Add minimum distances from the current position
    int lowerBound = cost;
    for (int i = 0; i < n; i++) {
        if (find(path.begin(), path.end(), i) == path.end()) {
            lowerBound += dist[currPos][i]; // Add cost to the next city
        }
    }

    return lowerBound;
}

// Function for Branch and Bound to solve the TSP
void tspBranchAndBound(int currPos, vector<int>& path, int count, int cost, int& bestCost) {
    if (count == n) {
        cost += dist[currPos][0]; // Return to the starting city
        bestCost = min(bestCost, cost); // Update the best cost found so far
        return;
    }

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (find(path.begin(), path.end(), nextCity) == path.end()) {
            path.push_back(nextCity); // Add city to the path
            int currentBound = bound(currPos, path, count + 1, cost);
            
            // Prune if the bound exceeds the best cost found so far
            if (currentBound < bestCost) {
                tspBranchAndBound(nextCity, path, count + 1, cost + dist[currPos][nextCity], bestCost);
            }
            path.pop_back(); // Remove the city from the path after exploring
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> path;
    path.push_back(0); // Starting at city 0

    int bestCost = INT_MAX;
    tspBranchAndBound(0, path, 1, 0, bestCost);

    cout << "The minimum cost of the tour is: " << bestCost << endl;
    return 0;
}
