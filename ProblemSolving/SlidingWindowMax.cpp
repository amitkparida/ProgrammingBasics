
// Sliding Window Maximum (Maximum of all subarrays of size K). 
// Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Naive method
//Time Complexity : O(N*K), The outer loop runs N - K + 1 times and the inner loop runs K times for every iteration of the outer loop.So time complexity is O((n - k + 1) * k) which can also be written as O(N * K)
//Auxiliary Space : O(1)
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	int j, max;
	vector<int> ans;
	int n = nums.size();

	for (int i = 0; i <= n - k; i++) {
		max = nums[i];

		for (j = i; j < i + k; j++) {
			if (nums[j] > max)
				max = nums[j];
		}

		//for (j = 1; j < k; j++) {
		//	if (nums[i + j] > max)
		//		max = nums[i + j];
		//}

		ans.push_back(max);
	}

	return ans;
}


// https://www.youtube.com/watch?v=m-Dqu7csdJk
/*
We create a Deque DQ of capacity k, that stores only useful elements of current window of k elements.
An element is useful if it is in the current window and is greater than all other elements on the left 
side of it in the current window.We process all array elements one by one and maintain DQ to contain 
useful elements of the current windowand these useful elements are maintained in sorted order.
The element at front of the DQ is the largestand the element at the rear of DQ is the smallest of the current window.
*/

// Time Complexity : O(N).It seems more than O(N) at first look.It can be observed that every element of the array is addedand removed at most once.So there are total of 2n operations.
// Auxiliary Space : O(K).Elements stored in the dequeue take O(K) space.

vector<int> maxSlidingWindow1(vector<int>& nums, int k)
{
	// Create a Double Ended Queue, dq that will store indexes of array elements. 
	// The queue will store indexes of useful elements in every window and it will maintain decreasing order 
	// of values from front to rear in dq, i.e., arr[dq.front[]] to arr[dq.rear()] are sorted in decreasing order
	deque<int> dq(k);
	vector<int> ans;

	// Process first k (or first window) elements of array
	for (int i = 0; i < k; i++) {
		// For every element, the previous smaller elements are useless so remove them from dq
		while ((!dq.empty()) && nums[i] >= nums[dq.back()])
			dq.pop_back(); // Remove from rear

		// Add new element at the rear of the queue
		dq.push_back(i);
	}

	//Process the rest of elements from nums[k] to nums[size - 1]
	for (int i = k; i < nums.size(); ++i) {
		//The element at the front of the queue is the largest element of the previous window. So push it to ans vector
		ans.push_back(nums[dq.front()]);

		// Remove the elements which are out of this window
		while ((!dq.empty()) && dq.front() <= i - k)
			dq.pop_front(); // Remove from front of queue

		// Remove all elements smaller than the currently being added element (remove useless elements)
		while ((!dq.empty()) && nums[i] >= nums[dq.back()])
			dq.pop_back();

		// Add current element at the rear of Qi
		dq.push_back(i);
	}

	// Print the maximum element of last window
	ans.push_back(nums[dq.front()]);

	return ans;
}


//Striver: https://www.youtube.com/watch?v=CZQGRp93K4k
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
	deque <int> dq;
	vector <int> ans;
	for (int i = 0; i < nums.size(); i++) {
		if (!dq.empty() && dq.front() == i - k)
			dq.pop_front();

		while (!dq.empty() && nums[dq.back()] < nums[i])
			dq.pop_back();

		dq.push_back(i);
		if (i >= k - 1)
			ans.push_back(nums[dq.front()]);
	}
	return ans;
}


// https://www.youtube.com/watch?v=l_CFMVPKv2Q
vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
	deque<int> dq;
	vector<int> ans;

	for (int i = 0; i < k; i++) {
		while (!dq.empty() && dq.back() < nums[i]) {
			dq.pop_back();
		}
		dq.push_back(nums[i]);
	}
	ans.push_back(dq.front());

	for (int i = k; i < nums.size(); i++) {
		if (dq.front() == nums[i - k]) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back() < nums[i]) {
			dq.pop_back();
		}
		dq.push_back(nums[i]);
		ans.push_back(dq.front());
	}

	return ans;
}


int main() {
	vector<int> arr{ 1, 2, 3, 1, 4, 5, 2, 3, 6 };

	for (auto e : maxSlidingWindow(arr, 3)) {
		cout << e << " ";
	}
}