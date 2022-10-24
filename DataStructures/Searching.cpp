
#include <algorithm>
#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++) {
		if (key == arr[i]) {
			return i;
		}
	}

	return -1;
}

int linearSearchSorted(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++) {
		if (key == arr[i]) {
			return i;
		}
		else if (key < arr[i]) {
			return -1;
		}
	}

	return -1;
}

int linearSearchRecursive(int arr[], int size, int key)
{
    if (0 == size) {
        return -1;
    }
    else if (key == arr[size - 1]) {
        return (size - 1);
    }
    else {
        return linearSearchRecursive(arr, size - 1, key);
    }
}

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

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (key == arr[mid]) {
            return mid;
        }
        else if (key > arr[mid]) {
            return binarySearchRecursive(arr, mid + 1, high, key);
        }
        else { //key < arr[mid]
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
    }

    return -1;
}

int main()
{
    int arr[] = { 2, 20, 4, 10, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = linearSearch(arr, size, 10);
    if (index == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index " << index << endl;
    }

    //Sort the array as BinarySearch() takes sorted array (increasing) as input 
    sort(arr, arr + size); 
    //sort(arr, arr + size, greater<int>()); // For sorting in decreasing order

    index = binarySearch(arr, size, 10);
    if (index == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index " << index << endl;
    }

    index = binarySearchRecursive(arr, 0, size - 1, 10);
    if (index == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index " << index << endl;
    }
}