// undirected unweighted graph
#include<iostream>
#include<vector>
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
};

int main()
{
   Graph graph(5);
   graph.addEdge(0, 1);
   graph.addEdge(1, 2);
   graph.addEdge(1, 3);
   graph.addEdge(2, 3);
   graph.addEdge(2, 4);

   graph.print();
   return 0;
}