
// Find the largest element in an array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Using sorting
//Time Complexity : O(nlogn))
//Space Complexity : O(n)

int findLargestElement(int arr[], int n) {
	std::sort(arr, arr + n);
	return arr[n - 1];
}

//int findLargest(vector<int>& arr) {
//	std::sort(arr.begin(), arr.end());
//	return arr[arr.size() - 1];
//}


//Better solution
//Time Complexity : O(n))
//Space Complexity : O(1)
int findLargestElement1(int arr[], int n) {
	int largest = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}

	return largest;
}


//================================================================

// Find second largest element in an array



int main() {
	int arr[]{ 1,2,8,7,3,11,24,6,5 };
	cout << findLargestElement(arr, sizeof(arr)/sizeof(arr[0]));
}

