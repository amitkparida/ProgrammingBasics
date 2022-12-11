#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;









//Sort characters in a string By frequency
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


//In the SRE interview: Get k most frequent elements from an array
vector<int> topKFrequentElements(vector<int>& arr, int k) {
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


vector<int> topKFrequentElements1(vector<int>& arr, int k) {
    unordered_map<int, int> umap;
    vector<int> res{};

    for (auto i: arr) {
        umap[arr[i]]++;
    }

    if (k > umap.size()) {
        cout << "Invalid input" << endl;
        return res;
    }

    // To prioritize w.r.t the pair.second, you need to define custom comparator function
    
    //auto cmp = [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.second < rhs.second; };
    //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

    struct cmp {
        bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

    for (auto elm : umap) {
        q.push(elm);
    }

    for (int i = 0; i < k; i++) {
        res.push_back(q.top().first);
        q.pop();
    }

    return res;
}



int main() {
    vector<int> arr{ 1,1,1,3,3,5 };

    for (auto ele : topKFrequentElements1(arr, 2))
        cout << ele << endl; //1, 2

    return 0;
}


