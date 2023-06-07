// TOPIC: std::priority_queue In C++ (Priority Queue)

// 0. std::priority_queue is a container adaptor that provides constant time lookup of the largest OR smallest element.
// 1. By default std::vector is the container used inside.
// 2. Cost of insertion and deletion is O(logN).
// 3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

// WHAT IS PRIORITY QUEUE??
// It’s a binary heap based structure where we can sort and store elements in max/min fashion so that every time we need 
// the largest/smallest element, we just pop it off from the top instead of sorting and computing the whole thing again.

// What is heap (binary heap)? 
// It’s a tree like structure with these conditions :
// - Complete binary tree
// - Min heap : Every node should be smaller than the ones below it. So the element at the top (root node) will be the min one.
// - Max heap : Every node should be bigger than the ones below it. So the element at the top (root node) will be the max one.

// Relationship between array indexes and tree element in Heap / Complete Binary Tree:
// - An array can be used to store the nodes of a Heap in the following way.
// - If the index of any element in the array is i, the element in the index 2i + 1 will become the left child 
//   and element in 2i + 2 index will become the right child.
// - Also, the parent of any element at index i is given by the lower bound of (i - 1) / 2.


// PROGRAM
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool compare(int lhs, int rhs) {
    return lhs < rhs;
}
int main() {
    //max heap - push: ascending, pop: descending
    std::priority_queue<int> q;
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q.push(elm); 
    }
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;

    
    //min-heap - push: descending, pop: ascending
    //Notice the 2 additional arguments below.
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q2.push(elm); 
    }
    while (!q2.empty()) {
        std::cout << q2.top() << " ";
        q2.pop();
    }
    std::cout << std::endl;


    //Using lambda to compare elements.
    //push: ascending, pop: descending
    auto cmp = [](int left, int right) { return left < right; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { 
        q3.push(elm); 
    }
    while (!q3.empty()) {
        std::cout << q3.top() << " ";
        q3.pop();
    }
    std::cout << std::endl;


    //Using function pointer to compare elements.
    //push: ascending, pop: descending
    std::priority_queue<int, vector<int>, decltype(&compare)> q4(compare);
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q4.push(elm);
    }
    while (!q4.empty()) {
        std::cout << q4.top() << " ";
        q4.pop();
    }
    std::cout << std::endl;

    //Using function object to compare elements.
    //push: ascending, pop: descending
    struct compObj {
        bool operator()(int lhs, int rhs) {
            return lhs < rhs;
        }
    };
    std::priority_queue<int, vector<int>, compObj> q5;
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q5.push(elm);
    }
    while (!q5.empty()) {
        std::cout << q5.top() << " ";
        q5.pop();
    }
    std::cout << std::endl;
}



//Problems: Sort characters in a string By frequency
using namespace std;
string frequencySort(string s) {
    unordered_map<char, int> umap;

    for (int i = 0; i < s.size(); i++) {
        umap[s[i]]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto j : umap) {
        pq.push({ j.second,j.first });
    }

    string mystr = "";
    while (!pq.empty()) {
        for (int i = 0; i < pq.top().first; i++) {
            mystr += pq.top().second;
        }
        pq.pop();
    }
    return mystr;
}


//In the SRE interview: Get k most frequent elements 

vector<int> GetMoreFrequentElements(const vector<int>& arr, int k) {
    unordered_map<int, int> m;
    vector<int> res{};

    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
    }

    if (k > m.size()) {
        cout << "Invalid input" << endl;
        return res;
    }

    priority_queue<pair<int, int>> q;

    for (auto ele : m) {
        q.push({ ele.second, ele.first });
    }

    for (int i = 0; i < k; i++) {
        res.push_back(q.top().second);
        q.pop();
    }

    return res;
}

//int main() {
//    vector<int> arr{ 1,1,1,2,2,3 };
//
//    for (auto ele : GetMoreFrequentElements(arr, 2))
//        cout << ele << endl; //1, 2
//
//    return 0;
//}
