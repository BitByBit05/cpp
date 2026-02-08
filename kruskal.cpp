#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Your specific type definition
typedef pair<pair<int, int>, int> Edge;

// DSU logic stays the same - it's the "engine" of Kruskal's
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

void kruskal(int V, vector<Edge>& edgesVector) {
    // 1. SORTING: Your way (sorting by the 'second' element which is weight)
    sort(edgesVector.begin(), edgesVector.end(), [](const Edge& a, const Edge& b) {
        return a.second < b.second;
    });

    DSU dsu(V);
    int mst_weight = 0;

    cout << "Edges in MST (using pairs):" << endl;

    for (int i = 0; i < edgesVector.size(); i++) {
        int u = edgesVector[i].first.first;  // Accessing your nested pair
        int v = edgesVector[i].first.second;
        int w = edgesVector[i].second;

        // 2. CHECK FOR CYCLES: If u and v aren't connected, take the edge
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mst_weight += w;
            cout << "Node " << u << " - Node " << v << " (Weight: " << w << ")" << endl;
        }
    }
    cout << "Total MST Weight: " << mst_weight << endl;
}

int main() {
    int V = 5;
    // Using your structure: {{u, v}, weight}
    vector<Edge> edgesVector = {
        {{0, 3}, 5}, {{0, 4}, 2}, {{0, 1}, 4},
        {{1, 2}, 6}, {{1, 3}, 3}, {{2, 3}, 8}, {{3, 4}, 10}
    };

    kruskal(V, edgesVector);
    return 0;
}
*/
/*
class WeightedGraph
{
private:
    int V;
    // Each element in the vector is a list of pairs (neighbor, weight)
    vector<list<pair<int, int>>> adj;
    vector<char> names;
    vector<pair<pair<int, int>, int>> edgesVector;

public:
    WeightedGraph(int nodes)
    {
        this->V = nodes;
        adj.resize(nodes);
        names.resize(nodes);
    }

    void addNode(int index, char name)
    {
        names[index] = name;
    }

    // Edge from u to v with weight w
    void addEdge(int u, int v, int weight)
    {
        edgesVector.emplace_back(make_pair(v, u), weight);
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    void sortedArrayKruskal()
    {
        for (int i = 0; i < edgesVector.size(); i++)
        {
            for (int j = i; j < edgesVector.size(); j++)
            {
                if (edgesVector[j].second < edgesVector[i].second)
                {
                    auto k = edgesVector[j];
                    edgesVector[j] = edgesVector[i];
                    edgesVector[i] = k;
                }
            }
        }
    }

    void kruskal()
    {
        
    }
};

int main()
{
    WeightedGraph g(5);

    g.addNode(0, 'A');
    g.addNode(1, 'B');
    g.addNode(2, 'C');
    g.addNode(3, 'D');
    g.addNode(4, 'E');

    g.addEdge(0, 3, 5); // A-B weight 10
    g.addEdge(0, 4, 2);  // B-C weight 5
    g.addEdge(0, 1, 4); // A-C weight 15
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 10);

    g.kruskal();
    return 0;
}
*/


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
