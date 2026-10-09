#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Graph {
int V;
vector<vector<pair<int, int>>> adj;
public:
Graph(int v) : V(v), adj(v) {}
void addEdge(int u, int v, int w) {
adj[u].push_back({v, w});
adj[v].push_back({u, w});
}
void primMST() {
typedef tuple<int, int, int> T; // {weight, vertex, parent}
priority_queue<T, vector<T>, greater<T>> pq;
vector<bool> inMST(V, false);
int total = 0;
cout << "Edges in MST:" << endl;
pq.push({0, 0,-1});
while (!pq.empty()) {
auto [w, u, parent] = pq.top();
pq.pop();
if (inMST[u]) continue;
inMST[u] = true;
total += w;
if (parent !=-1)
cout << parent << "- " << u << " (weight " << w << ")" <<
endl;
for (auto [v, wt] : adj[u])
if (!inMST[v])
pq.push({wt, v, u});
}
cout << "Total weight of MST: " << total << endl;
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
g.primMST();
return 0;
}