// TOPIC: Difference between TREE & GRAPH

// TREE :
// 0. Only one path exist between two vertices (Nodes).
// 1. Root node is the starting node of the tree.
// 2. Tree doesn't have loops.
// 3. Number of edges: n-1 (where n is number of nodes)
// 4. Tree looks like Hierarchicalaa
// 5. All trees are graph.

// GRAPH :
// 0. More than one path is allowed between two vertices.
// 1. There is no root node concept (we can start from any node).
// 2. There can be loop in graph.
// 3. Number of edges are not defined.
// 4. Graph looks like Network.
// 5. All graphs are not tree.


//Check if given graph is Tree or not.
#include<iostream>
#include <list>
#include <limits.h>
#include <vector>
using namespace std;

bool isCyclic(int src, int prt, vector<vector<int>> adj, vector<bool> visited) {
	visited[src] = true;
	for (auto i : adj[src]) {
		if (!visited[i]) {
			if (isCyclic(i, src, adj, visited)) return true;
		}
		else if (i != prt) return true;
	}
	return false;
}

bool isTree(int n, vector<vector<int>> adj) {
	vector<bool> visited(n, false);

	int startingNode = 0;
	if (isCyclic(startingNode, -1, adj, visited)) return false;

	for (int u = 0; u < n; u++)
		if (!visited[u])
			return false;

	return true;
}

void addEdge(vector<vector<int>>& adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<vector<int>> adj)
{
	for (int v = 1; v < adj.size(); ++v) {
		cout << v << " -> ";
		for (int i = 0; i < adj[v].size(); i++) {
			cout << adj[v][i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int V = 6;

	vector<vector<int>> adj;
	adj.resize(V + 1);

	addEdge(adj, 1, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 6);
	addEdge(adj, 4, 6);
	printGraph(adj);

	cout << endl << "Is the Graph a Tree? " << isTree(1, adj) << endl;
	//cout << endl << "Is the Graph a Tree? " << std::boolalpha << isTree(1, adj) << endl; //Prints false/true, not 0/1, if you use std::boolalpha
	
	//std::cout << " bool = " << std::boolalpha << true << std::endl;
	//std::cout << " bool = " << std::noboolalpha << false << std::endl;

	return 0;
}

