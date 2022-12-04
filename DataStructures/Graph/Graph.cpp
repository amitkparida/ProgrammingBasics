

// https://leetcode.com/discuss/study-guide/2043791/graph-all-in-one-must-watch-for-beginners

//===========================================================================================================

// Adjacent List representation of graph

#include <iostream>
#include <vector>
using namespace std;

// A utility function to add an edge in an undirected graph.
void addEdge(vector<vector<int>> &adj, int u, int v)
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


/*
//Adjacent List representation, taking input from console

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

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
*/


//===========================================================================================================


/*
//Adjacent Matrix representation using vector, taking input from console
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

	cin >> V >> E;

	// declare the adjacent matrix
	vector<vector<int>> adj;

	//Resize the 2D vector as adj[V+1][V+1].  Size = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size will be V.
	adj.resize(V + 1, vector<int>(V + 1));

	// take edges as input
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	//Print graph
	cout << endl << "The Graph (Adjacent Matrix) is: " << endl;
	for (int i = 1; i < adj.size(); ++i) { // Initially i = 1, j = 1 since graph is 1 based. i = 0, j = 0 if graph starts at 0, not 1.
		for (int j = 1; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
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

*/


//===========================================================================================================


/*
//Adjacent Matrix representation using array
#include <iostream>
#include <vector>
using namespace std;

const int V = 6; // V = no of nodes/vertices

void addEdge(int adj[][V + 1], int u, int v) {
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void printGraph(int adj[][V + 1])
{
	cout << endl << "The Graph (Adjacent Matrix) is: " << endl;
	for (int i = 1; i < V + 1; ++i) { // Initially i = 1, j = 1 since graph is 1 based. i = 0, j = 0 if graph starts at 0, not 1.
		for (int j = 1; j < V + 1; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int adj[V + 1][V + 1] = {0};

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
*/


//===========================================================================================================