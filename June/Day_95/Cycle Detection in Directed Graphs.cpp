#include <iostream>
#include <vector>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack); // Utility function for DFS

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    bool isCyclic(); // Returns true if there is a cycle in this graph
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
    // Mark the current node as visited and add it to the recursion stack
    visited[v] = true;
    recStack[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int u : adj[v]) {
        // If the adjacent vertex is not visited, then recur for that adjacent vertex
        if (!visited[u] && isCyclicUtil(u, visited, recStack)) {
            return true;
        }
        // If the adjacent vertex is already in the recursion stack, then a cycle is found
        else if (recStack[u]) {
            return true;
        }
    }

    // Remove the vertex from recursion stack
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic() {
    // Mark all the vertices as not visited and not part of the recursion stack
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    // Call the recursive helper function to detect a cycle in different DFS trees
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Create a graph
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);

    cout << "Graph contains cycle: " << (g1.isCyclic() ? "Yes" : "No") << endl;

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    cout << "Graph contains cycle: " << (g2.isCyclic() ? "Yes" : "No") << endl;

    return 0;
}

