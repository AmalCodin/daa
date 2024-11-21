#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubarraySum(const vector<int>& arr) {
    int maxSum = arr[0], currentSum = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
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
