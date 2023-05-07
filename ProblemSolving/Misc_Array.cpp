
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
	for (int i = 1; i < n; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}

	return largest;
}


//================================================================

// Find second largest element in an array

//Using sorting
//Time Complexity : O(nlogn + n)
//Space Complexity : O(n)
int findSecondLargestElement(int arr[], int n) {
	std::sort(arr, arr + n);

	for (int i = n - 2; i >= 0; i--) { //This loop is required if there are multiple largest elements
		if (arr[i] < arr[n - 1]) {
			return arr[i];
		}
	}

	return -1;
}

//Better solution
//Time Complexity : O(2n)
//Space Complexity : O(1)
int findSecondLargestElement1(int arr[], int n) {
	int largest = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}

	int slargest = -1;

	for (int i = 0; i < n; i++) {
		if (arr[i] > slargest && arr[i] != largest) {
			slargest = arr[i];
		}
	}

	return slargest;
}

//Optimal solution
//Time Complexity : O(n)
//Space Complexity : O(1)
int findSecondLargestElement2(int arr[], int n) {
	int largest = arr[0];
	int slargest = -1;

	for (int i = 1; i < n; i++) {
		if (arr[i] > largest) {
			slargest = largest;
			largest = arr[i];
		}
		else if (arr[i] < largest && arr[i] > slargest) {
			slargest = arr[i];
		}
	}

	return slargest;
}


//================================================================

// Check if an array is sorted

bool isSorted(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}

	return true;
}


int main() {
	int arr[]{ 1,2,8,7,3,11, 24, 24, 24,6,5 };
	//int arr[]{ 24, 24, 24, 24 };
	cout << findSecondLargestElement2(arr, sizeof(arr)/sizeof(arr[0]));
}
