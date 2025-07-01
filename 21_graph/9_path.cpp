#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;

    public:

    Graph(int V, bool isUndir=true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);   // u ka niegnbour v
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbour = l[u];
            cout<<u<<" : ";
            for(int v : neighbour){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
 
    void dfshelper(int u, vector<bool> &vis){   // O(V + E)
        vis[u] = true;
        cout<<u<<" ";

        list<int> neighbours = l[u];
        for(int v : neighbours){
            if(!vis[v]){
                dfshelper(v, vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(7, false);
        dfshelper(0, vis);
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string path){
        if(src == dest){
            cout<<path<<dest<<endl;
            return;
        }
        vis[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                pathHelper(v, dest, vis, path);
            }

        }
        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void path(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";

        pathHelper(src, dest, vis, path);
    }
};

int main()
{
   Graph graph(8, false);
//    graph.addEdge(1, 0);
//    graph.addEdge(0, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);
 // cycle
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.path(5, 1);
   return 0;
}