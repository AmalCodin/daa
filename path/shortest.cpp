#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
using namespace std;
const int V = 5; // Number of vertices
int minDistance(vector<int>& dist, vector<bool>& sptSet) {
int min = numeric_limits<int>::max(), min_index;
for (int v = 0; v < V; v++) {
if (!sptSet[v] && dist[v] <= min) {
min = dist[v];
min_index = v;
}
}
return min_index;
}
void dijkstra(int graph[V][V], int src) {
vector<int> dist(V, numeric_limits<int>::max());
vector<bool> sptSet(V, false);
dist[src] = 0;
for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet);
sptSet[u] = true;
for (int v = 0; v < V; v++) {
if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() &&
dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}

cout << "Vertex Distance from Source\n";
for (int i = 0; i < V; i++) {
cout << i << "\t\t" << dist[i] << "\n";
}
}
int main() {
int graph[V][V] = { { 0, 10, 0, 30, 100 },
{ 10, 0, 50, 0, 0 },
{ 0, 50, 0, 20, 10 },
{ 30, 0, 20, 0, 60 },
{ 100, 0, 10, 60, 0 } };
auto start = chrono::high_resolution_clock::now();
dijkstra(graph, 0);
auto end = chrono::high_resolution_clock::now();
chrono::duration<double, micro> duration = end - start;
cout << "Time taken: " << duration.count() << " microseconds\n";
return 0;
}