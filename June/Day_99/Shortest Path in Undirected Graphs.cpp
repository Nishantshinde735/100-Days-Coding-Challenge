#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void shortestPath(int src); // Function to find shortest paths from a source vertex
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list (because the graph is undirected)
}

void Graph::shortestPath(int src) {
    // Create a queue for BFS
    queue<int> q;

    // Distance of all vertices from src
    vector<int> dist(V, INT_MAX);

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    q.push(src);

    // BFS starting from source vertex
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Traverse all adjacent vertices of u
        for (int v : adj[u]) {
            // If the vertex v has not been visited (dist[v] is still INT_MAX)
            if (dist[v] == INT_MAX) {
                // Update the distance of v
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    // Create a graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    int src = 0;
    cout << "Shortest paths from vertex " << src << ":" << endl;
    g.shortestPath(src);

    return 0;
}
