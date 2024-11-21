#include <iostream>
#include <limits>
#include <vector>
#include <chrono>
using namespace std;
class Graph {
int V; // Number of vertices
vector<vector<int>> capacity; // Capacity matrix
public:
Graph(int V);
void addEdge(int u, int v, int w);
int fordFulkerson(int s, int t);
bool bfs(int s, int t, vector<int>& parent);
};
Graph::Graph(int V) {
this->V = V;
capacity.resize(V, vector<int>(V, 0));
}
void Graph::addEdge(int u, int v, int w) {
capacity[u][v] = w;
}
bool Graph::bfs(int s, int t, vector<int>& parent) {
vector<bool> visited(V, false);
visited[s] = true;
parent[s] = -1;
vector<int> queue;
queue.push_back(s);
while (!queue.empty()) {
int u = queue.front();

queue.erase(queue.begin());
for (int v = 0; v < V; v++) {
if (!visited[v] && capacity[u][v] > 0) {
if (v == t) {
parent[v] = u;
return true;
}
queue.push_back(v);
parent[v] = u;
visited[v] = true;
}
}
}
return false;
}
int Graph::fordFulkerson(int s, int t) {
int u, v;
int max_flow = 0;
vector<int> parent(V);
while (bfs(s, t, parent)) {
int path_flow = numeric_limits<int>::max();
for (v = t; v != s; v = parent[v]) {
u = parent[v];
path_flow = min(path_flow, capacity[u][v]);
}
for (v = t; v != s; v = parent[v]) {
u = parent[v];
capacity[u][v] -= path_flow;
capacity[v][u] += path_flow;
}
max_flow += path_flow;
}
return max_flow;
}
int main() {
auto start = chrono::high_resolution_clock::now();
Graph g(6);
g.addEdge(0, 1, 16);

g.addEdge(0, 2, 13);
g.addEdge(1, 2, 10);
g.addEdge(1, 3, 12);
g.addEdge(2, 1, 4);
g.addEdge(2, 4, 14);
g.addEdge(3, 2, 9);
g.addEdge(3, 5, 20);
g.addEdge(4, 3, 7);
g.addEdge(4, 5, 4);
int max_flow = g.fordFulkerson(0, 5);
cout << "The maximum possible flow is " << max_flow << endl;
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
return 0;
}