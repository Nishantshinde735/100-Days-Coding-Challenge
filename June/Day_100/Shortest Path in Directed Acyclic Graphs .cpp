#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
}

// A recursive function to perform topological sort on the graph
void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<pair<int, int>> adj[]) {
    visited[v] = true;

    for (auto& i : adj[v]) {
        int node = i.first;
        if (!visited[node])
            topologicalSortUtil(node, visited, Stack, adj);
    }

    Stack.push(v);
}

// Function to find the shortest paths from a source vertex to all other vertices
void shortestPath(vector<pair<int, int>> adj[], int V, int start) {
    stack<int> Stack;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    // Perform topological sort
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack, adj);
    }

    // Initialize the source vertex distance to itself as 0
    dist[start] = 0;

    // Process vertices in topological order
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MAX) {
            for (auto& i : adj[u]) {
                int v = i.first;
                int weight = i.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
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
    int V = 6; // Number of vertices
    vector<pair<int, int>> adj[V];

    // Add edges to the graph
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, -1);
    addEdge(adj, 4, 5, -2);

    int start = 1; // Starting vertex
    cout << "Following are shortest distances from vertex " << start << " to all other vertices:" << endl;
    shortestPath(adj, V, start);

    return 0;
}

