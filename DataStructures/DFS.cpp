

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




// From https://www.youtube.com/watch?v=kVyIhwYnLNs

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

vector<vector<int>> Vec;
vector<bool> visited;

void dfs(const vector<vector<int>>& Vec, int s) {
    stack<int> Stk;
    Stk.push(s);
    visited[s] = true;
    while (!Stk.empty()) {
        int node = Stk.top();
        Stk.pop();
        cout << "Visited: " << node << " ";
        for (int i = 0; i < Vec[node].size(); ++i) {
            if (!visited[Vec[node][i]]) {
                Stk.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }
    }
}

int main()
{
    return 0;
}