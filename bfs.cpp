#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
int V;
vector<vector<int>> adj;
public:
Graph(int v) : V(v), adj(v) {}
void addEdge(int u, int v) {
adj[u].push_back(v);
adj[v].push_back(u);
}
void BFS(int start) {
vector<bool> visited(V, false);
queue<int> q;
visited[start] = true;
q.push(start);
while (!q.empty()) {
int u = q.front();
q.pop();
cout << u << " ";
for (int v : adj[u]) {
if (!visited[v]) {
visited[v] = true;
q.push(v);
}
}
}
cout << endl;
}
};
int main() {
int V, E, u, v;
cout << "Enter number of vertices and edges: ";
cin >> V >> E;
Graph g(V);
cout << "Enter the edges (u v):" << endl;
for (int i = 0; i < E; i++) {
cin >> u >> v;
g.addEdge(u, v);
}
int start;
cout << "Enter the starting vertex: ";
cin >> start;
cout << "BFS traversal: ";
g.BFS(start);
return 0;
}