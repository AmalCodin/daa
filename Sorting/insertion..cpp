#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
int main() {
std::vector<int> arr = {12, 11, 13, 5, 6};
auto start = std::chrono::high_resolution_clock::now();
std::sort(arr.begin(), arr.end());
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed_time = end - start;
std::cout << "Sorted array: ";
for (int num : arr) {
std::cout << num << " ";
}
std::cout << "\nExecution time: " << std::chrono::duration_cast<std::chrono::microseconds>
(elapsed_time).count() << " microseconds" << std::endl;
return 0;
}