#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
using namespace std;
const int INF = numeric_limits<int>::max();
void floydWarshall(vector<vector<int>>& graph, int source) {
int V = graph.size();
vector<vector<int>> dist = graph;
for (int k = 0; k < V; k++) {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][k] != INF && dist[k][j] != INF) {
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

}
}
}
cout << "Shortest distances from source vertex " << source << ":\n";
for (int i = 0; i < V; i++) {
if (dist[source][i] == INF) {
cout << "Vertex " << i << " is unreachable from vertex " << source << ".\n";
} else {
cout << "Distance to vertex " << i << " is " << dist[source][i] << ".\n";
}
}
}
int main() {
int V = 4;
vector<vector<int>> graph = {
{0, 3, INF, 7},
{8, 0, 2, INF},
{5, INF, 0, 1},
{2, INF, INF, 0}
};
int source = 0;
auto start = chrono::high_resolution_clock::now();
floydWarshall(graph, source);
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
cout << "Time taken: " << duration << " microseconds\n";
return 0;
}