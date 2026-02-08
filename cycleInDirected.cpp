#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
private:
    int n;
    list<int> *l;
public:
    Graph(int n) {
        this->n = n;
        l = new list<int>[n];
    }
    void addEdge(int u, int v) {
        l[u].push_back(v);
    }
    void printAdjacencyList() {
        for(int i=0; i<n; i++) {
            for (int j : l[i]) {
                cout << i << "\t" << j <<"\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    void cycleDetection(int curr, bool vis[], bool recursionPath[]) {
        
    }

};

int main() {
    
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.printAdjacencyList();
}