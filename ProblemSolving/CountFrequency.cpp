#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//Counting frequencies of array elements
//A simple solution is to run two loops. For every item count number of times, it occurs.
//Time Complexity : O(n^2)
//Space Complexity : O(1)
void countFrequency(int arr[], int n)
{
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) 
    {
        if (visited[i] != true) 
        {
            int count = 1;
            for (int j = i + 1; j < n; j++) 
            {
                if (arr[i] == arr[j]) 
                {
                    visited[j] = true;
                    count++;
                }
            }
            cout << arr[i] << " " << count << endl;
        }
    }
}

//Using hashing (unordered_map)
//Time Complexity : O(n)
//Auxiliary Space : O(n)
void countFrequency1(int arr[], int n)
{
    unordered_map<int, int> mp;

    // Traverse through array elements and count frequencies
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Traverse through map and print frequencies
    for (auto x : mp) {
        cout << x.first << " " << x.second << endl;
    }
}

// In the above efficient solution, how to print elements in same order as they appear in input? 
//Time Complexity : O(n)
//Auxiliary Space : O(n)
void countFrequency2(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // To print elements according to first occurrence, traverse array one more time print frequencies 
    // of elements and mark frequencies as -1 so that same element is not printed multiple times.
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] != -1)
        {
            cout << arr[i] << " " << mp[arr[i]] << endl;
            mp[arr[i]] = -1;
        }
    }
}

//Sorted Array
void countFrequency3(int arr[], int n)
{
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int count = 1;

        // Move the index ahead whenever you encounter duplicates
        for ( ; i < n - 1 && arr[i] == arr[i + 1]; i++) {
            count++;
        }

        cout << arr[i] << ": " << count << endl;
    }
}




//Sort characters in a string By frequency
// Time Complexity: O(N + N * Log N + N * Log N) = O(N * Log N)
// Reason:
//  1 insertion in heap takes O(Log N), For N insertions O(N* LogN). (HEAP = Priority Queue)
//  1 deletion in heap takes O(Log N), For N insertions O(N* LogN).
//  Unordered Map takes O(1) for 1 Insertion.
//  N is the length of the String (input)
// 
// Space Complexity: O(N)

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
//Time Complexity : O(K log D + D log D), where D is the count of distinct elements in the array.
// - To remove the top of the priority queue O(log D) time is required, so if k elements are removed then O(k log D) time is required
// - To construct a priority queue with D elements, O(D log D) time is required.
// 
//Auxiliary Space : O(D), where D is the count of distinct elements in the array.

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

    int arr1[] = { 10, 20, 20, 10, 10, 20, 5, 20, 40 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    countFrequency3(arr1, n);

    return 0;
}


