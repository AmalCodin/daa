#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
using namespace std;

// Function to find the maximum crossing subarray sum
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    // Include elements on the left of mid
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;

    // Include elements on the right of mid
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    // Return the sum of the left and right parts
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubarraySum(const vector<int>& arr, int left, int right) {
    if (left == right) // Base case: single element
        return arr[left];

    int mid = left + (right - left) / 2;

    // Recursively find the maximum subarray sum in the left half, right half, and crossing the middle
    int leftMax = maxSubarraySum(arr, left, mid);
    int rightMax = maxSubarraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    // Return the maximum of the three
    return max({leftMax, rightMax, crossMax});
}

int main() {
    // Example array
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    // Find maximum subarray sum
    int maxSum = maxSubarraySum(arr, 0, arr.size() - 1);

    // Stop measuring time
    auto end = chrono::high_resolution_clock::now();

    // Calculate elapsed time in microseconds
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Print the result
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Time Taken: " << duration << " microseconds" << endl;

    return 0;
}
