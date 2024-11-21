#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function to find the maximum subarray sum using brute force
int maxSubarraySum(const vector<int>& arr) {
    int maxSum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int currentSum = 0;
            for (int k = i; k <= j; ++k) {
                currentSum += arr[k];
            }
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main() {
    // Example array
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    // Find maximum subarray sum
    int maxSum = maxSubarraySum(arr);

    // Stop measuring time
    auto end = chrono::high_resolution_clock::now();

    // Calculate elapsed time in microseconds
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Print the result
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Time Taken: " << duration << " microseconds" << endl;

    return 0;
}
