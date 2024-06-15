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
    bool topologicalSort(); // Function to perform topological sort using Kahn's algorithm
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::topologicalSort() {
    vector<int> inDegree(V, 0);

    // Compute in-degrees of all vertices
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0; // Count of visited vertices
    vector<int> topOrder; // Topological order

    // One by one dequeue vertices from queue and enqueue their adjacent vertices
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);

        // Iterate through all the neighboring nodes of dequeued node u and decrease their in-degree by 1
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }

        count++;
    }

    // Check if there was a cycle
    if (count != V) {
        cout << "Graph contains a cycle, topological sorting not possible." << endl;
        return false;
    }

    // Print topological order
    cout << "Topological Order: ";
    for (int i = 0; i < topOrder.size(); i++) {
        cout << topOrder[i] << " ";
    }
    cout << endl;

    return true;
}

int main() {
    // Create a graph
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
