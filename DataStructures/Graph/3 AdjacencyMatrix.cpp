// Adjacency Matrix representation:
// An adjacency matrix is a 2D array of size V x V where V is the number of vertices in the graph. It is a square matrix.
// It is used to represent the graph by storing a 1 at position (i, j) if there is an edge from vertex i to vertex j,
// and 0 otherwise.


//Adjacency Matrix representation using vector, taking input from console

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

	cin >> V >> E;

	// declare the adjacent matrix
	vector<vector<int>> adjmat;

	//Resize the 2D vector as adj[V + 1][V + 1].  Size = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size will be V.
	adjmat.resize(V + 1, vector<int>(V + 1));

	// take edges as input
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		adjmat[u][v] = 1;
		adjmat[v][u] = 1;
	}

	/* OR, you can give input like below 2D vector: (0th row and 0th column is ignored for 1 based graph)

	vector<vector<int>> adjmat
	{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1},
		{0, 1, 1, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1, 0, 0}
	};
	*/

	//Print graph
	cout << endl << "The Graph (Adjacent Matrix) is: " << endl;
	for (int i = 1; i < adjmat.size(); ++i) { // Initialize i = 1, j = 1 since graph is 1 based. i = 0, j = 0 if graph starts at 0, not 1.
		for (int j = 1; j < adjmat[i].size(); j++) {
			cout << adjmat[i][j] << " ";
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




//===========================================================================================================


/*
//Adjacency Matrix representation using array
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


