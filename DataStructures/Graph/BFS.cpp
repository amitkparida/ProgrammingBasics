/*
NOTES:
0. BFS is one of the tree / graph traversal algorithm.
1. When we travere tree or graph then order in which vertices are visited is very important.
2. BFS traversal algorithm traverse level wise.
3. BFS uses queue data structure in order to achieve level order traversal.
4. Graph has cycle so we have to keep the track of visited nodes and we should not visit them again.
5. Inorder to keep track of visited nodes we keep array of boolean where we initialize every element of array as false
   meaning non - visited, and as we visit some node we make this array element value true.

SOME USAGE :
1) Shortest Path and Minimum Spanning Tree for unweighted graph
2) Social Networking Websites
3) Broadcasting in Network
4) Finding all nodes within one connected component 

STEPS:
1. Push start node in QUEUE and mark it visited.
2. While QUEUE is not empty
3. Pop out a node from QUEUE and Push all non-visited adjacent nodes of popped node in queue and mark them visited
4. Go to Step 2
*/

//  https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/
// For class representaion : https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
//BFS using Adjacency List representation of graph
vector<int> BFS(int node, vector<vector<int>> adj) {
	vector <int> result;

	//Mark all the vertices as not visited
	vector <bool> visited;
	visited.resize(adj.size(), false); 

	//Create a queue for BFS
	queue<int> q;

	// Push the current vertex to queue and mark it as visited 
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		// Dequeue a vertex from queue and add it to the result vector 
		node = q.front();
		q.pop();
		result.push_back(node);

		// Traverse the adjacent vertices of the dequeued vertex. If a adjacent vertex has not been visited, then enqueue it and mark it as visited.
		for (int i = 0; i < adj[node].size(); i++) {
			if (!visited[adj[node][i]]) {
				q.push(adj[node][i]);
				visited[adj[node][i]] = true;
			}
		}

		//for (auto it : adj[node]) {
		//	if (!visited[it]) {
		//		q.push(it);
		//		visited[it] = true;
		//	}
		//}
	}

	return result;
}

int main() {
	int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge 

	cin >> V >> E;

	// declare the adjacent list 
	vector<vector<int>> adj;
	adj.resize(V + 1); // size  = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size = V.

	// take edges as input and add edges in the undirected graph.
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << "Following is Breadth First Traversal starting from vertex 1 \n";

	vector<int> result = BFS(1, adj); 

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

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



//BFS using Adjacency Matrix representation of graph
#include <iostream>
#include <queue>
using namespace std;

vector<int> BFS(int node, vector<vector<int>>& adjmat) {
	vector <int> result;
	vector<bool> visited(adjmat.size(), false); // size  = nodes + 1 if the input graph is 1 based. If the input graph starts at 0. then size = nodes.
	
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		// Dequeue a vertex from queue and add it to the result vector 
		node = q.front();
		q.pop();
		result.push_back(node);

		for (int i = 0; i < adjmat.size(); i++) {
			if (visited[i] == false && adjmat[node][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return result;
}

int main() {
	int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

	cin >> V >> E;

	//2D vector as adjmat[V+1][V+1].  Size = V + 1 if the input graph is 1 based. If the input graph starts at 0, then size will be V.
	vector<vector<int>> adjmat(V + 1, vector<int>(V + 1));

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

	//Print graph (Adjacency Matrix)
	cout << endl << "The Graph (Adjacent Matrix) is: " << endl;
	for (int i = 1; i < adjmat.size(); ++i) { // Initialize i = 1, j = 1 since graph is 1 based. i = 0, j = 0 if graph starts at 0, not 1.
		for (int j = 1; j < adjmat[i].size(); j++) {
			cout << adjmat[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Following is Breadth First Traversal starting from vertex 1 \n";

	vector<int> result = BFS(1, adjmat);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

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




