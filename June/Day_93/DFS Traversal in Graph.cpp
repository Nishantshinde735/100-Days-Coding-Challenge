#include <iostream>
#include <vector>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool>& visited); // A function used by DFS

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    void DFS(int v); // DFS traversal from a given vertex v
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

int main() {
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);

    return 0;
}
