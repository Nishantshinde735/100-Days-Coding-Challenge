#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
}

bool Graph::isCyclic() {
    vector<int> inDegree(V, 0);

    // Compute in-degrees of all vertices
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0; // Count of visited vertices

    // Process each vertex in the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        // Decrease the in-degree of all adjacent vertices
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If count of visited vertices is not equal to the number of vertices
    // then the graph contains a cycle
    return (count != V);
}

int main() {
    // Create a graph
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);

    if (g1.isCyclic()) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    if (g2.isCyclic()) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
