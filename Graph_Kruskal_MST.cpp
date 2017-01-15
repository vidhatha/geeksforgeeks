#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ipair = integer pair
typedef pair<int,int> edgepair;

class Graph
{
    int V;
    vector< pair<int, edgepair> > edges;
    vector<int> parent; //parent element 
    vector<int> sizeofset;  //size of the set
    
    public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int find(int vt);
    void union_set(int set_u, int set_v);
    void kruskalMST();
};

Graph::Graph(int v)
{
    V = v;
    
    //Initialize parent of every vertex as itself
    //Initial size of every set is 1 (just one vertex)
    for(int i=0;i<=v;i++)
    {
        parent.push_back(i);
        sizeofset.push_back(1);
    }
}

void Graph::addEdge(int u, int v, int weight)
{
    //Add edges u->v and v->u
    edges.push_back(make_pair(weight, make_pair(u, v)));
}

int Graph::find(int vt)
{
    if(parent[vt] == vt)
        return vt;
    return find(parent[vt]);
}

void Graph::union_set(int set_u, int set_v)
{
    int root1 = find(set_u);
    int root2 = find(set_v);
    
    //if both belong to the same set
    //then don't combine the sets
    if(root1 == root2) return;
    
    //Make tree with smaller height
    //a subtree of tree with higher height
    if(sizeofset[root1] >= sizeofset[root2])
    {
        parent[root2] = root1;
        sizeofset[root1] += sizeofset[root2];
    }
    else
    {
        parent[root1] = root2;
        sizeofset[root2] += sizeofset[root1];
    }
}
void Graph::kruskalMST()
{
    
    vector<edgepair> kmst;
    //sort the edges 
    sort(edges.begin(),edges.end());
    
    //iterate through the sorted edges
    int edgecount = 0;
    vector< pair<int, edgepair> >::iterator it;
    it = edges.begin();
    
    //we stop once we get V-1 edges
    //since no of edges=no of vertices-1 in MST
    while((edgecount<V-1) && (it != edges.end()))
    {
        //obtain the edge vertices
        int u = it->second.first;
        int v = it->second.second;
        
        //find their respective sets
        int set_u = find(u);
        int set_v = find(v);
        
        //if the two sets are disjoint
        //add the edge to kruskal MST
        //and merge the sets
        if(set_u != set_v)
        {
            kmst.push_back(make_pair(u,v));
            //increment edge counter
            ++edgecount;
            union_set(set_u,set_v);
        }
        
        ++it;
        
    }
    
    vector<edgepair>::iterator et;
    for(et=kmst.begin(); et!=kmst.end(); ++et)
        cout<<et->first<<" - "<<et->second<<endl;
}

// Driver program to test above functions
int main()
{
    /* Let us create above shown weighted
       and unidrected graph */
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
 
    cout << "Edges of MST are \n";
    g.kruskalMST();
 
    //cout << "\nWeight of MST is " << mst_wt;
 
    return 0;
}

Time Complexity:
O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply
find-union algorithm. The find and union operations can take atmost O(LogV) time. So overall complexity is 
O(ELogE + ELogV) time.
The value of E can be atmost O(V2), so O(LogV) are O(LogE) same. 
Therefore, overall time complexity is O(ElogE) or O(ElogV)
