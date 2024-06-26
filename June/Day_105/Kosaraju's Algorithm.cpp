#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// A class that represents a directed graph
class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list

    
    void fillOrder(int v, bool visited[], stack<int>& Stack);


    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w); // Add an edge to the graph
    void printSCCs(); // Prints all SCCs
    Graph getTranspose(); // Returns the transpose of the graph
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (auto i : adj[v])
        if (!visited[i])
            DFSUtil(i, visited);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++)
        for (auto i : adj[v])
            g.adj[i].push_back(v);
    return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int>& Stack) {
    visited[v] = true;

    for (auto i : adj[v])
        if (!visited[i])
            fillOrder(i, visited, Stack);

    Stack.push(v);
}

void Graph::printSCCs() {
    stack<int> Stack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, visited, Stack);

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }

    delete[] visited;
}

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components in the graph:\n";
    g.printSCCs();

    return 0;
}
