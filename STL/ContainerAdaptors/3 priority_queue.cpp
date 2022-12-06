// TOPIC: std::priority_queue In C++ (Priority Queue)

// WHAT IS IT ??

// NOTES:
// 0. std::priority_queue is a container adaptor that provides constant time lookup of the 
//    largest OR smallest element.
// 1. By default std::vector is the container used inside.
// 2. Cost of insertion and extraction is logarithmic.
// 3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

// PROGRAM
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

template<typename T> void print_queue(T& q) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    {
        std::priority_queue<int> q;
        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
            q.push(elm); 
        }
        print_queue(q);
    }
    
    {
        std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
            q2.push(elm); 
        }
        print_queue(q2);
    }

    // Using lambda to compare elements.
    {
        auto cmp = [](int left, int right) { return (left) < (right); };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { q3.push(elm); }
        print_queue(q3);
    }
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


//In the SRE interview: Get k no. of more frequent elements 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> GetMoreFrequentElements(const vector<int>& arr, int k) {
    unordered_map<int, int> m;
    vector<int> res{};

    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
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
