#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Function to calculate the maximum value for the 0/1 knapsack problem
int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    
    // Create a 2D table to store results of subproblems
    // dp[i][j] will store the maximum value for a knapsack capacity j using the first i items
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            // If the current item's weight is less than or equal to the knapsack capacity
            if (items[i - 1].weight <= w) {
                // We can either include the item or exclude it
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                // If the item can't be included, take the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell contains the maximum value that can be carried in the knapsack
    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    // Calculate the maximum value for the given knapsack capacity
    int totalValue = knapsack(capacity, items);

    // Output the result
    cout << "Maximum total value in knapsack: " << totalValue << endl;

    return 0;
}
