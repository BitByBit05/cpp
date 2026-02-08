#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l; // (neighbor, weight)

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void dijkstra(int src)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min heap → (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (auto neighbor : l[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++)
        {
            cout << "To " << i << " = " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.dijkstra(0);

    return 0;
}
