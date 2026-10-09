#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct Edge {
int u, v, w;
};
class Graph {
    int V;
vector<Edge> edges;
public:
Graph(int v) : V(v) {}
void addEdge(int u, int v, int w) {
edges.push_back({u, v, w});
}
// directed edge u-> v
void bellmanFord(int src) {
vector<int> dist(V, INF);
dist[src] = 0;
for (int i = 1; i <= V- 1; i++) {
for (const Edge& e : edges) {
if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
dist[e.v] = dist[e.u] + e.w;
}
}
for (const Edge& e : edges) {
// check for negative cycle
if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
cout << "Graph contains a negative weight cycle." << endl;
return;
}
}
cout << "Shortest distances from source " << src << ":" << endl;
for (int i = 0; i < V; i++) {
cout << src << "-> " << i << " : ";
if (dist[i] == INF) cout << "INF" << endl;
else
cout << dist[i] << endl;
}
}
};
int main() {
int V, E, u, v, w;
cout << "Enter number of vertices and edges: ";
cin >> V >> E;
Graph g(V);
cout << "Enter the edges (u v w):" << endl;
for (int i = 0; i < E; i++) {
cin >> u >> v >> w;
g.addEdge(u, v, w);
}
int start;
cout << "Enter the source vertex: ";
cin >> start;
g.bellmanFord(start);
return 0;
}