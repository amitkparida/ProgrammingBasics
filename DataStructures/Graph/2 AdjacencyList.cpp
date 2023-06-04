
// Adjacency List representation of graph:
// 1. An adjacency list represents a graph as an array of linked lists. 
// 2. Each index of the array represents a vertex and each element in its linked list represents 
//    the other vertices that are connected to the vertex by an edge.
// 3. The size of the array is equal to the number of vertices.


#include <iostream>
#include <vector>
using namespace std;

// A utility function to add an edge in an undirected graph.
void addEdge(vector<vector<int>>& adj, int u, int v)
{
	//Add an edge from src to dest. A new element is inserted to the adjacent list of src.
	adj[u].push_back(v);

	// Since graph is undirected, add an edge from dest to src also
	adj[v].push_back(u);
}

// A utility function to print the adjacency list representation of graph
void printGraph(vector<vector<int>> adj)
{
	for (int v = 1; v < adj.size(); ++v) { //Initially v = 1 since graph is 1 based. v = 0 if graph starts at 0, not 1.
		cout << v << " -> ";
		for (int i = 0; i < adj[v].size(); i++) {
			cout << adj[v][i] << " ";
		}
		cout << endl;
	}

	//for (int v = 1; v <= adj.size(); ++v) {
	//	cout << v << " -> ";
	//	for (auto elm : adj[v]) {
	//		cout << elm << " ";
	//	}
	//	printf("\n");
	//}
}

int main()
{
	int V = 6; // V = no of nodes/vertices

	// declare the adjacent list 
	vector<vector<int>> adj;

	//Resize the 2D vector as adj[V+1][]
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


//Output
//1 -> 2 4
//2 -> 1 4 3
//3 -> 2 6
//4 -> 1 5 2 6
//5 -> 4
//6 -> 3 4


//===========================================================================================================



/*

//Adjacency List representation, taking input from console

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int V, E, u, v; // V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

	cin >> V >> E;

	// declare the adjacent list
	vector<vector<int>> adj;

	//Resize the 2D vector as adj[V+1][]
	adj.resize(V + 1); // size  = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size will be V.

	// take edges as input
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//Print graph
	cout << endl << "The Graph (Adjacent List) is: " << endl;
	for (int node = 1; node < adj.size(); ++node) { // Initially node = 1 since graph is 1 based. node = 0 if graph starts at 0, not 1.
		cout << node << " -> ";
		for (int i = 0; i < adj[node].size(); i++) {
			cout << adj[node][i] << " ";
		}
		cout << endl;
	}

	return 0;
}

//Input format
//6 7    <------- 6 = No of nodes, 7 = no of edges
//1 2
//1 4
//4 5
//2 4
//2 3
//3 6
//4 6

//Output:
//1 -> 2 4
//2 -> 1 4 3
//3 -> 2 6
//4 -> 1 5 2 6
//5 -> 4
//6 -> 3 4

*/



