#include <iostream>
#include <vector>
#include <list>

using namespace std;

class WeightedGraph
{
private:
    int V;
    // Each element in the vector is a list of pairs (neighbor, weight)
    vector<list<pair<int, int>>> adj;
    vector<char> names;

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
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    void display()
    {
        for (int i = 0; i < V; i++)
        {
            cout << names[i] << " is connected to:\n";
            for (auto edge : adj[i])
            {
                int neighborIndex = edge.first;
                int weight = edge.second;
                cout << "  -> " << names[neighborIndex] << " (weight: " << weight << ")\n";
            }
        }
    }
};

int main()
{
    WeightedGraph g(3);

    g.addNode(0, 'A');
    g.addNode(1, 'B');
    g.addNode(2, 'C');

    g.addEdge(0, 1, 10); // A-B weight 10
    g.addEdge(1, 2, 5);  // B-C weight 5
    g.addEdge(0, 2, 15); // A-C weight 15

    g.display();

    return 0;
}