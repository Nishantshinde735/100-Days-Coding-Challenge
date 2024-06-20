#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void primMST(struct Graph* graph) {
    int V = graph->V;
    vector<int> key(V, numeric_limits<int>::max());
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (int i = 0; i < graph->E; i++) {
            int v = (graph->edge[i].src == u)? graph->edge[i].dest : graph->edge[i].src;
            if (!inMST[v] && graph->edge[i].weight < key[v]) {
                key[v] = graph->edge[i].weight;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << i << " - " << 0 << " \t" << key[i] << endl;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 6;  // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 3;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 1;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 1;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 4;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 5;

    primMST(graph);

    return 0;
}
