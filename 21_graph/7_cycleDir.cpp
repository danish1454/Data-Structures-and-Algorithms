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

    bool isCycleDirHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                if(isCycleDirHelper(v, vis, recPath)){
                    return true;
                }
            }
            else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleDirHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
   Graph graph(4, false);
//    graph.addEdge(1, 0);
//    graph.addEdge(0, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);
 // cycle
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

   cout<<graph.isCycleDir();
   return 0;
}