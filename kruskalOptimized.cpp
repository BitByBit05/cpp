#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// DSU (Disjoint Set Union) to detect cycles
struct DSU
{
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
            parent[root_i] = root_j;
    }
};

void kruskal(int V, vector<Edge> &edges)
{
    // 1. Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    DSU dsu(V);
    vector<Edge> mst;
    int mst_weight = 0;

    // 2. Process edges
    for (Edge &e : edges)
    {
        if (dsu.find(e.u) != dsu.find(e.v))
        {
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            mst_weight += e.weight;
        }
    }

    // 3. Print Result
    cout << "Edges in MST:\n";
    for (Edge &e : mst)
    {
        cout << e.u << " -- " << e.v << " == " << e.weight << endl;
    }
    cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;
}

int main()
{
    int V = 5; // Total nodes
    vector<Edge> edges = {
        {0, 3, 5}, {0, 4, 2}, {0, 1, 4}, {1, 2, 6}, {1, 3, 3}, {2, 3, 8}, {3, 4, 10}};

    kruskal(V, edges);

    return 0;
}