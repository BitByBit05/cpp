#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int v;
    list<int> *l; //dynamic array of lists

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList() {
        for (int i = 0; i < v; i++) {
            cout << i << " : ";
            for (int j : l[i]) {
                cout << j << " "; 
            }
            cout << endl;
            
        }
        
    }

    void bfs() {
        vector <bool> visited(v, false);
        queue<int> myQueue;
        myQueue.push(0);
        visited[0] = true;
        while (myQueue.size() > 0) {
            int u = myQueue.front();
            myQueue.pop();
            cout << u << "\t";
            for (int v : l[u] ) {
                if ( !visited[v] ) { // immediate neighbour(not visited)
                    visited[v] = true;
                    myQueue.push(v);
                }
                
            }
            
        }
        cout << endl;
        
    }

    // This is the function the user calls
    void dfs(int startNode)
    {
        vector<bool> visited(v, false);
        dfsHelper(startNode, visited);
        cout << endl;
    }

    // This is the internal recursive function (private)
    void dfsHelper(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << "\t";
        for (int neighbor : l[u])
        {
            if (!vis[neighbor])
            {
                dfsHelper(neighbor, vis);
            }
        }
    }
};

int main() {
    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    //g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();
    g.bfs();
    g.dfs(0);
    cout << endl;
    return 0;
}