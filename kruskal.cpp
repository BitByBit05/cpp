#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class Graph
{
    int V;

    struct Edge
    {
        int u, v, w;
    };

    vector<Edge> edges;
    vector<int> parent;

public:
    Graph(int V)
    {
        this->V = V;
        parent.resize(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b)
    {
        parent[find(a)] = find(b);
    }

    void kruskal()
    {
        // sort edges by weight
        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b)
             { return a.w < b.w; });

        int totalWeight = 0;

        cout << "Edges in MST:\n";

        for (auto e : edges)
        {
            if (find(e.u) != find(e.v))
            { // no cycle
                unite(e.u, e.v);
                cout << e.u << " → " << e.v << " : " << e.w << endl;
                totalWeight += e.w;
            }
        }

        cout << "Total MST Weight: " << totalWeight << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 3, 5);
    g.addEdge(0, 4, 2);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 10);

    g.kruskal();

    return 0;
}
