#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// A class that represents an undirected graph
class Graph {
    int V; // Number of vertices
    list<int>* adj; // A dynamic array of adjacency lists

    // A recursive function that finds articulation points using DFS traversal
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // To add an edge to the graph
    void findAPs(); // Function that finds and prints all articulation points
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]) {
    static int time = 0;
    int children = 0;

    visited[v] = true;

    disc[v] = low[v] = ++time;

    for (auto i : adj[v]) {
        int u = i;

        if (!visited[u]) {
            children++;
            parent[u] = v;
            APUtil(u, visited, disc, low, parent, ap);

            low[v] = min(low[v], low[u]);

            if (parent[v] == -1 && children > 1)
                ap[v] = true;

            if (parent[v] != -1 && low[u] >= disc[v])
                ap[v] = true;
        } else if (u != parent[v]) {
            low[v] = min(low[v], disc[u]);
        }
    }
}

void Graph::findAPs() {
    bool* visited = new bool[V];
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    bool* ap = new bool[V];

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    cout << "Articulation points in the graph:\n";
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";

    delete[] visited;
    delete[] disc;
    delete[] low;
    delete[] parent;
    delete[] ap;
}

int main() {
    cout << "Articulation points in the graph:\n";
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.findAPs();

    return 0;
}
