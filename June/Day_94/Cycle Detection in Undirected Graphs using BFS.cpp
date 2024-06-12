#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph class represents an undirected graph using adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

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
    adj[w].push_back(v); // Add v to w’s list (because the graph is undirected)
}

bool Graph::isCyclic() {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Parent array to store the parent nodes
    vector<int> parent(V, -1);

    // Queue for BFS
    queue<int> q;

    // Loop through all vertices to cover disconnected graphs
    for (int i = 0; i < V; ++i) {
        // If the vertex is not visited, perform BFS
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                // Visit all adjacent vertices of u
                for (int v : adj[u]) {
                    // If an adjacent vertex is not visited, mark it visited and enqueue it
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        parent[v] = u;
                    } else if (parent[u] != v) {
                        // If an adjacent vertex is visited and not parent of current vertex, then there is a cycle
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    // Create a graph
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 1);

    cout << "Graph contains cycle: " << (g1.isCyclic() ? "Yes" : "No") << endl;

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    cout << "Graph contains cycle: " << (g2.isCyclic() ? "Yes" : "No") << endl;

    return 0;
}
