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

    bool isBipartite(){
        queue<int> q;
        vector<int> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;
        vis[0] = 0; 

        while(q.size() > 0){
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }
                else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
   Graph graph(4, false);
   graph.addEdge(0, 1);
   graph.addEdge(0, 2);
   graph.addEdge(2, 3);
   graph.addEdge(1, 3);

    cout<<graph.isBipartite();
   return 0;
}