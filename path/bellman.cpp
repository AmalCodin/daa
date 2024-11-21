#include <iostream>
#include <vector>
#include <climits>

#include <chrono>
using namespace std;
struct Edge {
int source, destination, weight;
};
void bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int start) {
vector<int> distance(vertices, INT_MAX);
distance[start] = 0;
for (int i = 1; i <= vertices - 1; i++) {
for (const auto& edge : edgeList) {
if (distance[edge.source] != INT_MAX &&
distance[edge.source] + edge.weight < distance[edge.destination]) {
distance[edge.destination] = distance[edge.source] + edge.weight;
}
}
}
for (const auto& edge : edgeList) {
if (distance[edge.source] != INT_MAX &&
distance[edge.source] + edge.weight < distance[edge.destination]) {
cout << "Graph contains negative weight cycle" << endl;
return;
}
}
cout << "Vertex Distance from Source:" << endl;
for (int i = 0; i < vertices; i++) {
cout << i << "\t\t" << distance[i] << endl;
}
}
int main() {
auto start = chrono::high_resolution_clock::now();
int vertices = 5;
int edges = 8;
vector<Edge> edgeList = {
{0, 1, -1},
{0, 2, 4},
{1, 2, 3},
{1, 3, 2},
{1, 4, 2},
{3, 2, 5},
{3, 1, 1},
{4, 3, -3}

};
bellmanFord(vertices, edges, edgeList, 0);
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
return 0;
}