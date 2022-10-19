
/*
// From Udemy Abdul Bari course : https://www.udemy.com/course/datastructurescncpp/learn/lecture/13193650#overview
//BFS for Adjacency matrix representation of graph
#include <iostream>
#include <queue>

using namespace std;

void BFS(int vtx, int A[][8], int n) {
    queue<int> Q;
    int visited[8]{ 0 };

    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.emplace(vtx);

    // Explore
    while (!Q.empty()) {
        int u = Q.front();  // Vertex u for exploring
        Q.pop();
        for (int v = 1; v <= n; v++) {  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0) {  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
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

    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);

    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);


    return 0;
}
*/




//From : https://www.youtube.com/watch?v=0rg74kONSgU

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
1) Shortest Pathand Minimum Spanning Tree for unweighted graph
2) Social Networking Websites
3) Broadcasting in Network
4) Finding all nodes within one connected component 

STEPS:
1. Push start node in QUEUE and mark it visited.
2. While QUEUE is not empty
3. Pop out a node from QUEUE and Push all non-visited adjacent nodes of popped node in queue and mark them visited
4. Go to Step 2

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Vec;
vector <bool> visited;

void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < Vec[node].size(); i++) {
            if (!visited[Vec[node][i]]) {
                q.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }

    }
}

int main() {

    int N, u, v;
    cin >> N;

    Vec.resize(N + 1);
    visited.resize(N + 1);

    while (N--) {
        cin >> u >> v; 
        Vec[u].push_back(v);
        Vec[v].push_back(v);
    }

    BFS(1);

    return 0;
}


//Input format
//7
//1 2
//1 4
//4 5
//2 4
//2 3
//3 6
//4 6


