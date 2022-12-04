// TOPIC: Binary Search

// NOTES:
// 1. Binary Search technique works on sorted array. (both SORTED and ARRAY words are very important)
// 2. It works on divide and conquer (each iteration it divides array in half).

// ALGO:
// 1. Get middle element of array check if it is the one we are looking.
// 2. If yes, then we have found the number.
// 3. If no, then check if the middle element is bigger than our element.
// 4. If yes, then we will choose left half of the array.
// 5. Otherwise we will choose right half of the array.
// 6. Repeat this until we find the number or 

// COMPLEXITY:
// Worst Case Time:     O(logN))
// Best Case Time:      O(1)
// Average Case Time:   O(logN)

#include <algorithm>
#include <iostream>
using namespace std;

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

    //Sort the array as BinarySearch() takes sorted array (increasing) as input 
    sort(arr, arr + size); //Time complexity = O(NLogN)
    //sort(arr, arr + size, greater<int>()); // For sorting in decreasing order

    int index = binarySearch(arr, size, 10);
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

    //STL binary_search
    bool bPresent = binary_search(arr, arr + size, 10);
    if (bPresent == false) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present" << endl;
    }
}

//Time Complexity of Binary Search: O(logN)