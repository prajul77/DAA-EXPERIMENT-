#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
    // Disjoint Set Union (Union-Find)
    vector<int> parent, rnk;

public:
    DSU(int n) : parent(n), rnk(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rnk[a] < rnk[b])
            swap(a, b);

        parent[b] = a;

        if (rnk[a] == rnk[b])
            rnk[a]++;

        return true;
    }
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int v) : V(v) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(),
             [](const Edge& a, const Edge& b) {
                 return a.w < b.w;
             });

        DSU dsu(V);
        int total = 0;

        cout << "Edges in MST:" << endl;

        for (const Edge& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                cout << e.u << "- " << e.v
                     << " (weight " << e.w << ")" << endl;

                total += e.w;
            }
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

    g.kruskalMST();

    return 0;
}