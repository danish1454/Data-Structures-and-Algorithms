#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;

    public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);   // u ka niegnbour v
        l[v].push_back(u);
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
 
    bool undirCycleHelper(int src, int par, vector<bool> &vis){  // par = parent
        vis[src] = true;
        list<int> neighbours = l[src];
        
        for(int v : neighbours){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
            }
            else{
                if(v != par){
                return true;
                }
            }
        }
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
};

int main()
{
   Graph graph(8);
//    graph.addEdge(0, 1);
//    graph.addEdge(0, 2);
//    graph.addEdge(1, 3);
//    graph.addEdge(2, 4);
//    graph.addEdge(3, 4);
//    graph.addEdge(3, 5);
//    graph.addEdge(4, 5);
//    graph.addEdge(5, 6);
 // cycle
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    cout<<graph.isCycleDir();
   return 0;
}