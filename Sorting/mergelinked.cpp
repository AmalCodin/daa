#include <iostream>
#include <list>
#include <chrono>
using namespace std;
using namespace std::chrono;
list<int> merge(list<int>& left, list<int>& right) {
list<int> result;

auto leftIt = left.begin();
auto rightIt = right.begin();
while (leftIt != left.end() && rightIt != right.end()) {
if (*leftIt < *rightIt) {
result.push_back(*leftIt);
leftIt++;
} else {
result.push_back(*rightIt);
rightIt++;
}
}
while (leftIt != left.end()) {
result.push_back(*leftIt);
leftIt++;
}
while (rightIt != right.end()) {
result.push_back(*rightIt);
rightIt++;
}
return result;
}
list<int> mergeSort(list<int>& arr) {
if (arr.size() <= 1) {
return arr;
}
list<int> left, right, result;
int middle = arr.size() / 2;
auto it = arr.begin();
for (int i = 0; i < middle; i++) {
left.push_back(*it);
it++;
}
for (int i = middle; i < arr.size(); i++) {
right.push_back(*it);
it++;
}
left = mergeSort(left);
right = mergeSort(right);
result = merge(left, right);
return result;
}
int main() {
list<int> arr = {12, 11, 13, 5, 6, 7};
auto start = high_resolution_clock::now();

list<int> sortedArr = mergeSort(arr);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << "Sorted array:";
for (int num : sortedArr) {
cout << " " << num;
}
cout << "\nExecution time: " << duration.count() << " microseconds" << endl;
return 0;
}