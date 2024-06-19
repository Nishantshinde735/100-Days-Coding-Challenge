#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <limits.h>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight); // Uncomment this line if the graph is undirected
}

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<pair<int, int>> adj[], int V, int start) {
    // Priority queue to store vertices that are being preprocessed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance vector to store the shortest distance from the source to each vertex
    vector<int> dist(V, INT_MAX);

    // Insert the source vertex into the priority queue and initialize its distance as 0
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Traverse all adjacent vertices of the dequeued vertex u
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                // Update the distance of v
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int V = 9; // Number of vertices
    vector<pair<int, int>> adj[V];

    // Add edges to the graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    int start = 0; // Starting vertex
    cout << "Following are shortest distances from vertex " << start << " to all other vertices:" << endl;
    dijkstra(adj, V, start);

    return 0;
}
