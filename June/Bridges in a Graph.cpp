#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// A class that represents an undirected graph
class Graph {
    int V; // No. of vertices
    list<int>* adj; // A dynamic array of adjacency lists

    // A recursive function that finds and prints bridges
    // using DFS traversal
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector<pair<int, int>>& bridges);

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // To add an edge to the graph
    void findBridges(); // Function that finds and prints all bridges
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector<pair<int, int>>& bridges) {
    static int time = 0;
    visited[v] = true;

    disc[v] = low[v] = ++time;

    for (auto i : adj[v]) {
        int u = i;
        if (!visited[u]) {
            parent[u] = v;
            bridgeUtil(u, visited, disc, low, parent, bridges);

            low[v] = min(low[v], low[u]);

            if (low[u] > disc[v])
                bridges.push_back({v, u});
        }
        else if (u != parent[v])
            low[v] = min(low[v], disc[u]);
    }
}

void Graph::findBridges() {
    bool* visited = new bool[V];
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    vector<pair<int, int>> bridges;

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent, bridges);

    for (auto& bridge : bridges)
        cout << bridge.first << " -- " << bridge.second << endl;

    delete[] visited;
    delete[] disc;
    delete[] low;
    delete[] parent;
}

int main() {
    cout << "Bridges in the graph:\n";
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.findBridges();

    return 0;
}
