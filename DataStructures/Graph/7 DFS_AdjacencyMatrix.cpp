
//DFS using Adjacency Matrix representation of graph

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Non-recursive
vector<int> DFS(int node, const vector<vector<int>>& adjmat) {
    vector<int> result;

    vector<bool> visited(adjmat.size(), false);

    stack<int> Stk;
    Stk.push(node);
    visited[node] = true;

    while (!Stk.empty()) {
        node = Stk.top();
        Stk.pop();

        result.push_back(node);

        for (int i = 0; i < adjmat.size(); i++) {
            if (visited[i] == false && adjmat[node][i] == 1) {
                Stk.push(i);
                visited[i] = true;
            }
        }

    }

    return result;
}


//Recursive
void DFS_Recursive(int node, vector<vector<int>> adjmat, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (int i = 0; i < adjmat.size(); i++) {
        if (visited[i] == false && adjmat[node][i] == 1) {
            DFS_Recursive(i, adjmat, visited, result);
        }
    }
}

int main() {
    int V, E, u, v; //V = no of vertices/nodes, E = no of edges, (u, v) are source and destination nodes that represent an edge

    cin >> V >> E;

    //2D vector as adjmat[V][V].  Size = V if the input graph is 0 based. If the input graph starts at 1, then size will be V+1.
    vector<vector<int>> adjmat(V, vector<int>(V));

    // take edges as input
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }

    /*
     OR, you can give input like below 2D vector: (0th row and 0th column is ignored for 1 based graph)

    vector<vector<int>> adjmat
    {
        {0 1 1 1 0},
        {1 0 0 1 0},
        {1 0 0 0 1},
        {1 1 0 0 0},
        {0 0 1 0 0}
    };
    */

    //Print graph (Adjacency Matrix)
    cout << endl << "The Graph (Adjacent Matrix) is: " << endl;
    for (int i = 0; i < adjmat.size(); ++i) { // Initialize i = 0, j = 0 since graph is 0 based. i = 1, j = 1 if graph starts at 1, not 0.
        for (int j = 0; j < adjmat[i].size(); j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Following is Depth First Traversal starting from vertex 0 (Non-recursive) \n";
    vector<int> result = DFS(0, adjmat);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    cout << "Following is Depth First Traversal starting from vertex 0 using recursion \n";
    vector<bool> visited(adjmat.size(), false);
    result.clear();

    DFS_Recursive(0, adjmat, visited, result);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//Input format
//5 5    <------- 5 = No of nodes, 5 = no of edges
//0 2
//2 4
//0 1
//0 3
//1 3


//Output: (Note that the order of traversal could be different)
// 
// Following is Depth First Traversal starting from vertex 0 (Non - recursive)
// 0 3 2 4 1
// Following is Depth First Traversal starting from vertex 0 using recursion
// 0 1 3 2 4
