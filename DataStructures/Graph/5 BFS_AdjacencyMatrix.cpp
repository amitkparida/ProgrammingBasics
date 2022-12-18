
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


