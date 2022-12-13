// Find frequency of one element in an array

#include<iostream>
#include<unordered_map>
using namespace std;

//Array is not sorted
//Time Complexity: O(n) 
//Auxiliary Space : O(1)
int countFrequency(int arr[], int n, int x) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			count++;
		}
	}

	return count;
}


//Array is sorted. Find frequency of one element in the array
//Time Complexity : O(Log n + count) where count is number of occurrences.
//Space Complexity : O(1)
int binarySearch(int arr[], int size, int key) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (key == arr[mid]) {
            return mid;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else { //key < arr[mid]
            high = mid - 1;
        }
    }

    return -1;
}

int countFrequency1(int arr[], int n, int x)
{
    int index = binarySearch(arr, n, x);

    if (index == -1) {
        return 0;
    }

    // Count elements on left side.
    int count = 1;
    int left = index - 1;
    while (left >= 0 && arr[left] == x) {
        count++;
        left--;
    }

    // Count elements on right side.
    int right = index + 1;
    while (right < n && arr[right] == x) {
        count++;
        right++;
    }

    return count;
}


//Sorted array. Using STL
//Time Complexity : O(Logn)
//Auxiliary Space : O(1)
int countFrequency2(int arr[], int n, int x)
{
    //get the index of first occurrence of x
    int* low = lower_bound(arr, arr + n, x);

    //If element is not present, return 0
    if (low == (arr + n) || *low != x)
        return 0;

    //Else get the index of last occurrence of x. Note that we  are only looking in the subarray after first occurrence
    int* high = upper_bound(low, arr + n, x);

    //return count
    return high - low;
}


int main() {
    int arr[] = { 1, 2, 2, 3, 3, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countFrequency2(arr, n, 3);
	return 0;
}