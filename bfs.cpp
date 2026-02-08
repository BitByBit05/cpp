#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int v;
    list<int> *l;
    char *name;
public:
    Graph (int v){
        this->v = v;
        l = new list<int>[v];
        name = new char[v];
    }

    void addName (int v, char name){
        this->name[v] = name;
    }

    void addEdge (int v, int u){
        l[v].push_back(u);
        l[u].push_back(v);
    }

    int findIndex(char node) {
        for (int i = 0; i < v; i++) {
            if (name[i] == node){
                return i;
            }
        }
        return -1;
    }

    void displayEdge (){
        for (int i = 0; i < v; i++){
            cout << name[i] << " : ";
            for (int j : l[i]){
                cout << name[j] << " ";
            }
            cout << endl;
        }
    }

    void bfs (char source){
        int v = findIndex(source);
        if(v == -1) {
            char a;
            cout<<"Enter a valid node:"<<"    ";
            cin>>a;
            cout<<endl;
            bfs(a);
            return;
        }
        
        vector<bool> visited(this->v, false);
        queue<int> myQueue;
        myQueue.push(v);
        visited[v] = true;
        while(myQueue.size() > 0) {
            int u = myQueue.front();
            myQueue.pop();
            cout<<name[u]<<"\t";
            for(int j : l[u]) {
                if (!visited[j]) {
                    visited[j] = true;
                    myQueue.push(j);
                }
            }

        }
        cout<<endl;
    }
};

int main (){
    Graph g(8);
    g.addName(0, 'a');
    g.addName(1, 'b');
    g.addName(2, 'c');
    g.addName(3, 'd');
    g.addName(4, 'e');
    g.addName(5, 'f');
    g.addName(6, 'g');
    g.addName(7, 'h');

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 7);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);

    g.bfs('a');
    return 0;
}

//This is the end