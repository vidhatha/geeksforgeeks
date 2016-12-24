#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	int v;
	vector<list<int>> adjlist;
	
	public:
	Graph(int v);
	void addEdge(int u, int v);
	void BFS(int s);
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
void Graph::BFS(int s)
{
	//Mark all vertices as not visited
	vector<bool> visited(v);
	for(int i=0;i<v;i++)
	{
		visited.push_back(false);
	}
	
	//create a queue for BFS
	queue<int> q;
	
	//Mark the current node as visited and enque it
	visited[s] = true;
	q.push(s);
	
	// Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it
    list<int>::iterator it;
    while(!q.empty())
    {
    	int vt = q.front();
    	cout<<vt<<" ";
    	q.pop();
    	for(it=adjlist[vt].begin(); it!=adjlist[vt].end(); ++it)
    	{
    		if(!visited[*it])
    		{
    			visited[*it] = true;
    			q.push(*it);
    		}
    	}
    }
}

int main() {
	// your code goes here
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
	return 0;
}
