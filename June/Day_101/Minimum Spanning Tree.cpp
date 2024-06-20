#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint set data structure
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x]!= x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot!= yRoot) {
            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    }
};

// Edge structure
struct Edge {
    int src;
    int dest;
    int weight;
};

// Compare edges by weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Kruskal's algorithm for MST
vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    vector<Edge> mst;
    DisjointSet ds(numVertices);

    sort(edges.begin(), edges.end(), compareEdges);

    for (const Edge& edge : edges) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);
        if (srcRoot!= destRoot) {
            mst.push_back(edge);
            ds.unionSets(edge.src, edge.dest);
        }
    }

    return mst;
}

int main() {
    int numVertices = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    vector<Edge> mst = kruskalMST(edges, numVertices);

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
