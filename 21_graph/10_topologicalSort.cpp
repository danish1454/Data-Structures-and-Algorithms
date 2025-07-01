#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

    void topoSortHelper(int u, vector<bool> &vis, stack<int> &st){
        vis[u] = true;

        list<int> neighbours = l[u];
        for(int v : neighbours){
            if(!vis[v]){
                topoSortHelper(v, vis, st);
            }
        }
        st.push(u);
    }

    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> st;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSortHelper(i, vis, st);
            }
        }

        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
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

    graph.topoSort();

   return 0;
}