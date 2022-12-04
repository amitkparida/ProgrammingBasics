
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

    //Sort the array (increasing)
    sort(arr, arr + size); 
    //sort(arr, arr + size, greater<int>()); // For sorting in decreasing order

    index = linearSearchSorted(arr, size, 10);
    if (index == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index " << index << endl;
    }
}