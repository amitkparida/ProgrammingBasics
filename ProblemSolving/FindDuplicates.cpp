// Given an array of N + 1 size, where each element is between 1 and N. 
// Assuming there is only one duplicate number, your task is to find the duplicate number.

// https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


//Using sorting
//Time Complexity : O(Nlogn + N). Reason: NlogN for sorting the arrayand O(N) for traversing through the arrayand checking if adjacent elements are equal or not.But this will distort the array.
//Space Complexity : O(1)
int findDuplicate(vector <int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return arr[i];
        }
    }
    //for (int i = 1; i < n; i++) {
    //    if (arr[i] == arr[i - 1]) {
    //        return arr[i];
    //    }
    //}

    return -1;
}

//Using hashing (array). It won't work if any number in the array is greater than n
//Time Complexity : O(N), as we are traversing through the array only once.
//Space Complexity : O(N), as we are using extra space for frequency array.
int findDuplicate1(vector<int>& arr) {
    int n = arr.size();
    //int freq[n + 1] = { 0 }; //not allowed in VC++
    int* freq = new int[n + 1] {0};

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 0)
        {
            freq[arr[i]]++;
        }
        else
        {
            return arr[i];
        }
    }
    return 0;
}

// Using hashing (map)
int findDuplicate2(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        if (umap[arr[i]] == 0)
        {
            umap[arr[i]]++;
        }
        else
        {
            return arr[i];
        }
    }
    return 0;
}

//Using linked List Cycle (Slow and fast pointer) method
//Time complexity : O(N).Since we traversed through the array only once.
//Space complexity : O(1).
int findDuplicate3(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector <int> arr;
    arr = { 1,3,4,2,2 };
    cout << "The duplicate element is " << findDuplicate3(arr) << endl;
}