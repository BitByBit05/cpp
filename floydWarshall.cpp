#include <iostream>
using namespace std;

#define INF 99999
#define V 4 // number of vertices

int main()
{
    int dist[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    // Floyd–Warshall Algorithm
    for (int k = 0; k < V; k++) // intermediate vertex
    {
        for (int i = 0; i < V; i++) // source vertex
        {
            for (int j = 0; j < V; j++) // destination vertex
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
