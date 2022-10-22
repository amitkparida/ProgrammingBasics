

//===========================================================================================================

/*
//Adjacent Matrix representation
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodes, edges, u, v;
	cin >> nodes >> edges;

	// declare the adjacent matrix 
	vector<vector<int>> adj;
	adj.resize(nodes + 1);

	// take edges as input 
	for (int i = 0; i < edges; i++) {
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	return 0;
}
*/


//===========================================================================================================


/*
//Adjacent List representation
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nodes, edges, u, v;

	cin >> nodes >> edges;

	// declare the adjacent list 
	vector<vector<int>> adj;
	adj.resize(nodes + 1);

	// take edges as input 
	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	return 0;
}
*/


//===========================================================================================================


// A simple representation of graph using STL
#include <iostream>
#include <vector>
using namespace std;

// A utility function to add an edge in an undirected graph.
void addEdge(vector<vector<int>> &adj, int u, int v)
{
	//Add an edge from src to dest.  A new element is inserted to the adjacent list of src.
	adj[u].push_back(v);

	// Since graph is undirected, add an edge from dest to src also
	adj[v].push_back(u);
}

// A utility function to print the adjacency list representation of graph
void printGraph(vector<vector<int>> adj)
{
	for (int v = 1; v < adj.size(); ++v) { // v = 1 since graph is 1 based. v = 0 if graph starts at 0, not 1.
		cout << v << " -> ";
		for (int i = 0; i < adj[v].size(); i++) {
			cout << adj[v][i] << " ";
		}
		cout << endl;
	}

	//for (int v = 1; v <= V; ++v) {
	//	cout << v << " -> ";
	//	for (auto it : adj[v]) {
	//		cout << it << " ";
	//	}
	//	printf("\n");
	//}
}

int main()
{
	int V = 6; // V = no of nodes/vertices

	// declare the adjacent list 
	vector<vector<int>> adj;
	adj.resize(V + 1); // size  = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size will be V.

	addEdge(adj, 1, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 6);
	addEdge(adj, 4, 6);
	printGraph(adj);
	return 0;
}


//===========================================================================================================

