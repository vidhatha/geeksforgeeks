#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	int v;
	vector<list<int>> adjlist;
	void DFSUtil(int vt, vector<bool> &visited);
	
	public:
	Graph(int v);
	void addEdge(int u, int v);
	void DFS(int s);
};

Graph::Graph(int v)
{
	this->v = v;
	adjlist.resize(v);
}

void Graph::addEdge(int u, int v)
{
	adjlist[u].push_back(v);
}
void Graph::DFSUtil(int vt, vector<bool> &visited)
{
	//Mark the current node as visited and print it
	visited[vt] = true;
	cout<<vt<<" ";
	
	//recursively visit the adjacent vertices paths
	list<int>::iterator it;
	for(it=adjlist[vt].begin(); it!=adjlist[vt].end(); ++it)
    {
    	if(!visited[*it])
    		DFSUtil(*it,visited);
    }
}
void Graph::DFS(int s)
{
	vector<bool> visited(v);
	for(int i=0;i<v;i++)
		visited.push_back(false);
		
	//call the recursive helper function for DFS Graph Traversal
	DFSUtil(s,visited);
}

int main() {
	// your code goes here
   // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(0);
	return 0;
}
