#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
                return ans;
            }
        }
    }

    return ans;
}

vector<int> twoSum1(vector<int>& nums, int target)
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

// Sorted array: 
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
// find two numbers such that they add up to a specific target number. 
vector<int> twoSumSorted(vector<int>& numbers, int target) {
    //Two pointer approach
    int start = 0;
    int end = numbers.size() - 1;

    while (start < end) {
        int sum = numbers[start] + numbers[end];

        if (sum == target) {
            return vector<int>{start + 1, end + 1};
        }
        else if (sum < target) {
            start++;
        }
        else {
            end--;
        }
    }

    return vector<int>{-1, -1};
}

int main() {

    vector<int> nums{ 2, 4, 6, 8, 9 };

    for (auto i : twoSumSorted(nums, 20)) {
        cout<< i << " "; 
    }
}