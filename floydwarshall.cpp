#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int INF = 1000000000;

class Graph {
    int V;
    vector<vector<int>> d;

public:
    // distance matrix
    Graph(int v) : V(v), d(v, vector<int>(v, INF)) {
        for (int i = 0; i < V; i++)
            d[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        d[u][v] = w;
    }

    void floydWarshall() {
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    // directed edge u -> v
                    if (d[i][k] != INF && d[k][j] != INF &&
                        d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        cout << "All-pairs shortest distance matrix:" << endl;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (d[i][j] == INF)
                    cout << setw(5) << "INF";
                else
                    cout << setw(5) << d[i][j];
            }
            cout << endl;
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

    g.floydWarshall();

    return 0;
}