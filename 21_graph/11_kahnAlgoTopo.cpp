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

    void calcIndeg(vector<int> &indeg){    // indeg ==> inDegree
        for(int u=0;u<V;u++){
            list<int> neighbours = l[u];
            for(int v : neighbours){
                indeg[v]++;
            }
        }
    }

    void kahn(){
        vector<int>indeg(V, 0);
        queue<int> q;
        calcIndeg(indeg);
        //0 indeg nodes  -> starting point 
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbours = l[curr];
            for(int v : neighbours){
                indeg[v]--;
                if(indeg[v]==0){          // no pending dependencies
                    q.push(v);
                }
            }
        }
    } 
    
};

int main()
{
   Graph graph(6, false);
   graph.addEdge(2, 3);
   graph.addEdge(3, 1);
   graph.addEdge(4, 0);
   graph.addEdge(4, 1);
   graph.addEdge(5, 0);
   graph.addEdge(5, 2);

    graph.kahn();
   return 0;
}