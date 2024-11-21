#include <iostream>
#include <list>
#include <chrono>
void insertionSort(std::list<int>& lst) {
for (auto it = std::next(lst.begin()); it != lst.end(); ++it) {
int key = *it;
auto j = std::prev(it);
while (j != lst.begin() && *j > key) {
*std::next(j) = *j;
--j;
}
*std::next(j) = key;
}
}
int main() {
std::list<int> myList = {12, 11, 13, 5, 6};
auto start = std::chrono::high_resolution_clock::now();
insertionSort(myList);
auto end = std::chrono::high_resolution_clock::now();
std::cout << "Sorted list: ";
for (const auto& elem : myList) {
std::cout << elem << " ";
}
std::cout << "\n";
std::chrono::duration<double, std::micro> duration = end - start;
std::cout << "Execution time: " << duration.count() << " microseconds\n";
return 0;
}