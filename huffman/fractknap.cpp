#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Function to calculate the maximum value for the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double totalValue = 0.0; // Variable to store the total value

    // Iterate through the sorted items
    for (const auto& item : items) {
        if (item.weight <= capacity) {
            // If the item can be fully included, take it
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // If the item cannot be fully included, take the fractional part
            totalValue += (double)item.value * capacity / item.weight;
            break; // Knapsack is full
        }
    }

    return totalValue;
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
    double totalValue = fractionalKnapsack(capacity, items);

    // Output the result
    cout << "Maximum total value in knapsack: " << totalValue << endl;

    return 0;
}
