#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":" << endl;

        for (int i = 0; i < V; i++) {
            cout << src << "-> " << i << " : ";

            if (dist[i] == INT_MAX)
                cout << "INF" << endl;
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

    g.dijkstra(start);

    return 0;
}