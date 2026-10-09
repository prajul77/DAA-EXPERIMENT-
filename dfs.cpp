#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void dfsUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u])
            if (!visited[v])
                dfsUtil(v, visited);
    }

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
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

    cout << "DFS traversal: ";
    g.DFS(start);

    return 0;
}