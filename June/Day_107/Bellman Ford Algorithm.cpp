#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void BellmanFord(vector<Edge> edges, int V, int E, int src) {
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.src]!= INT_MAX && dist[e.src] + e.weight < dist[e.dest])
                dist[e.dest] = dist[e.src] + e.weight;
        }
    }

    for (Edge e : edges) {
        if (dist[e.src]!= INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
            cout << "Graph contains negative weight cycle";
            return;
        }
    }

    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 8;  // Number of edges

    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    BellmanFord(edges, V, E, 0);

    return 0;
}
