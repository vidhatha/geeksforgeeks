```c++
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>

using namespace std;

//ipair = integer pair
typedef pair<int,int> ipair;

class Graph
{
    int V;
    vector< list<ipair> > adjlist;
    
    public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void primMST(int source);
};

Graph::Graph(int v)
{
    V = v;
    adjlist.resize(v);
}

void Graph::addEdge(int u, int v, int weight)
{
    //Add edges u->v and v->u
    adjlist[u].push_back(make_pair(v, weight));
    adjlist[v].push_back(make_pair(u, weight));
}

void Graph::primMST(int source)
{
    //create a priority queue to store the nonMST nodes
    priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
    
    //create a vector for node weight and assign them to INFINITY
    int max_int = numeric_limits<int>::max();
    vector<int> nodeweight(V,max_int);
    
    //create a vector to store parent array which in turn stores MST
    vector<int> parent(V,-1);
    
    //To keep track of vertices included in the MST
    vector<bool> inMST(V, false);
    
    //insert source node into the pq
    //and initialize its weight to 0
    pq.push(make_pair(0,source));
    nodeweight[source] = 0;
    
    //Loop till pq is empty
    while(!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
        
        //include it in the MST
        inMST[u] = true;
        
        //calculate distance to adjacent vertices of u
        list<ipair>::iterator it;
        for(it=adjlist[u].begin(); it!=adjlist[u].end(); ++it)
        {
            //get vertex and weight of current adjacent of u
            int v = (*it).first;
            int weight = (*it).second;
            
            //if v is not in MST and nodeweight[v] is greater
            //than weight update its weight and push it into
            //the pq
            if((inMST[v]==false) && (nodeweight[v]>weight))
            {
                //update weight of v
                nodeweight[v] = weight;
                pq.push(make_pair(nodeweight[v],v));
                //update v's parent
                parent[v]=u;
            }
        }
    }
    
    //print MST using parent array
    for(int i=1;i<V;i++)
        cout<<parent[i]<<" - "<<i<<endl;
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.primMST(0);
 
    return 0;
}
```
Time Complexity:

The time complexity of the above code/algorithm looks O(V^2) as there are two nested while loops. 
If we take a closer look, we can observe that the statements in inner loop are executed O(V+E) times.
The inner loop has push() operation which takes O(LogV) time
So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) (For a connected graph, V = O(E))
