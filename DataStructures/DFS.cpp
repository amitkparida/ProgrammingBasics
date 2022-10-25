/* Depth First Search(DFS).
NOTES:
0. Depth - first search(DFS) is an algorithm(or technique) for traversing a tree / graph.
2. DFS uses stack OR we can use recursive approach.

APPLICATIONS OF DFS
0. To find minimum spanning tree and all pair shortest path tree.
1. Detecting cycle in a graph
2. Path finding
3. Topological sorting
4. To test graph is bipartite
5. Find strongly connected component of a graph
6. Maze related problems(find the shortest path)

STEPS:
1. Push start node in stack and mark it visited. 
2. While stack is not empty 
3. Pop out a node from stack and Push all non-visited adjacent node of popped node in stack and mark them visited. 
4. Go to Step 2
*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Non-recursive
vector<int> DFS(int node, const vector<vector<int>>& adj) {

    vector <int> result;

    vector <bool> visited;
    visited.resize(adj.size(), false); 

    stack<int> Stk;
    Stk.push(node);
    visited[node] = true;

    while (!Stk.empty()) {
        node = Stk.top();
        Stk.pop();
        
        result.push_back(node);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                Stk.push(it);
                visited[it] = true;
            }
        }

        //for (int i = 0; i < adj[node].size(); ++i) {
        //    if (!visited[adj[node][i]]) {
        //        Stk.push(adj[node][i]);
        //        visited[adj[node][i]] = true;
        //    }
        //}
    }

    return result;
}

//Using recursion
void DFS_Recursive(int node, vector<vector<int>> adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (auto it : adj[node]) {
        if (!visited[it]) {
            DFS_Recursive(it, adj, visited, result);
        }
    }

    //for (int i = 0; i < adj[node].size(); ++i) {
    //    if (visited[adj[node][i]] == false)
    //        DFS_Rec(adj[node][i], adj, visited, result);
    //}
}


void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int>> adj)
{
    for (int v = 0; v < adj.size(); ++v) { // v = 0 since graph is 0 based. v = 1 if graph starts at 1
        cout << v << " -> ";
        for (int i = 0; i < adj[v].size(); i++) {
            cout << adj[v][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; //V = no of vertices/nodes

    vector<vector<int>> adj;
    adj.resize(V); // size  = V if the input graph is 0 based. If the input graph starts at 1. then size = V+1.

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    cout << "The graph is: \n";
    printGraph(adj);


    cout << "Following is Depth First Traversal starting from vertex 0 (Non-recursive) \n";
    vector<int> result = DFS(0, adj);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    cout << "Following is Depth First Traversal starting from vertex 0 using recursion \n";
    vector <bool> visited;
    visited.resize(adj.size(), false);
    result.clear();

    DFS_Recursive(0, adj, visited, result);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    return 0;
}



//===========================================================================================================


/*
// From Abdul Bari course https://www.udemy.com/course/datastructurescncpp/learn/lecture/13193676#overview

#include <iostream>
#include <stack>

using namespace std;

// Based on Lecture
void DFS(int u, int A[][8], int n) {
    // Initialize visit tracking array and stack
    int visited[8]{ 0 };
    stack<int> stk;
    stk.emplace(u);

    // Visit start vertex u
    cout << u << ", " << flush;
    visited[u] = 1;  // Visited vertex u

    // Initial Adjacent vertex
    int v = 0;

    while (!stk.empty()) {
        while (v < n) {
            if (A[u][v] == 1 && visited[v] == 0) {
                stk.push(u); // Suspend exploring current vertex u
                u = v;  // Update current vertex as the next adjacent vertex

                // Visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1;  // Increment will make this 0
            }
            v++;
        }
        v = u;  // Can set v = 0 but setting v = u is better
        u = stk.top();  // Return to previous suspended vertex
        stk.pop();
    }
}

// Simpler and adds elements to stack from end
void dfs(int u, int A[][8], int n) {
    int visited[8]{ 0 };
    stack<int> stk;
    stk.emplace(u);

    while (!stk.empty()) {
        u = stk.top();
        stk.pop();

        if (visited[u] != 1) {
            cout << u << ", " << flush;
            visited[u] = 1;

            for (int v = n - 1; v >= 0; v--) {
                if (A[u][v] == 1 && visited[v] == 0) {
                    stk.emplace(v);
                }
            }
        }
    }
}

int main() {

    int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0} };

    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;

    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs(u, A, 8);
    cout << endl;

    return 0;
}
*/