// TOPIC: std::unordered_map In C++

// NOTES:
// 0. std::unordered_map is an associative container that contains key-value pairs with unique keys.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets. 
// 4. This allows fast access to individual elements, because after computing the hash of the value it refers to 
//    the exact bucket the element is placed into.

// WHY UNORDERED_MAP
// 0. maintain a collection of uniqe {key:value} pairs with fast insertion and removal.

// PROGRAM:
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<int, char> umap = { {1,'a'}, {3, 'b'},{2,'c'}};
    // Access
    cout << umap[1] << endl;
    cout << umap[2] << endl;
    cout << umap[3] << endl;

    // Update
    umap[1] = 'd';

    // Iterate
    for (auto& elm : umap) {
        cout << elm.first << " " << elm.second << endl;
    }
    cout << endl;

    // Find
    auto result = umap.find(2);
    if (result != umap.end()) {
        cout << "Found " << result->first << " " << result->second << '\n';
    }
    else {
        cout << "Not found\n";
    }

    return 0;
}



//Problems:
//Two sum

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ans;

    for (int i = 0; i != nums.size(); i++)
    {
        for (int j = i + 1; j != nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans = { i, j };
                return nums;
            }
        }
    }

    return ans;
}

vector<int> twoSum2(vector<int>& nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++) {
        if (umap.find(target - nums[i]) != umap.end()) {
            ans.push_back(umap[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }

        umap[nums[i]] = i;
    }

    return ans;
}


// First Unique Character in a String
int firstUniqChar(string s) {
    unordered_map<char, int> umap;

    for (int i = 0; i < s.length(); i++) {
        umap[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (umap[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}


// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"], ["nat", "tan"], ["ate", "eat", "te
// https://leetcode.com/problems/group-anagrams/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans{};
    unordered_map<string, vector<string>> umap;

    for (auto x : strs) {
        string sorted = x;
        sort(sorted.begin(), sorted.end());
        umap[sorted].push_back(x);
    }

    for (auto x : umap) {
        ans.push_back(x.second);
    }

    return ans;
}