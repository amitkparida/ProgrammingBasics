
// Intuition:
// 1. Merge Sort is a divide and conquers algorithm, it divides the given array into equal parts and then merges the 2 sorted parts.
// 2. There are 2 main functions :
//   - merge() : This function is used to merge the 2 halves of the array.It assumes that both parts of the array are sorted and merges both of them.
//   - mergeSort() : This function divides the array into 2 parts.low to mid and mid + 1 to high where,

// https://takeuforward.org/data-structure/merge-sort-algorithm/

#include <iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high) {
    int i = low; // starting index of left half of A[]
    int j = mid + 1; // starting index of right half of A[]
    
    int *temp = new int[high + 1]; // temporary array. You can write "int temp[high + 1];" if the compiler supports Variable Length Arrays
    int k = low; // starting index of temp array

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            temp[k++] = A[i++];
        }
        else {
            temp[k++] = A[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = A[i++];
    }
    while (j <= high) {
        temp[k++] = A[j++];
    }
    for (int i = low; i <= high; i++) {
        A[i] = temp[i];
    }

    delete[] temp;
}

void RecursiveMergeSort(int A[], int low, int high) {
    if (low < high) {
        // Calculate mid point
        int mid = low + (high - low) / 2;

        // Sort sub-lists
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);

        // Merge sorted sub-lists
        Merge(A, low, mid, high);
    }
}

void IterativeMergeSort(int A[], int n) {
    int p;
    for (p = 2; p <= n; p = p * 2) {
        for (int i = 0; i + p - 1 < n; i = i + p) {
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;
            Merge(A, low, mid, high);
        }
    }
    if (p / 2 < n) {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main() {

    int A[] = { 2, 5, 8, 12, 3, 6, 7, 10 };
    int n = sizeof(A) / sizeof(A[0]);

    RecursiveMergeSort(A, 0, n - 1);
    //IterativeMergeSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}


//Time Complexity = O(nLogn) <- Best, Worst, Average
//Auxiliary Space Complexity: O(n), We are using a temporary array to store elements in sorted order.

//Merge sort is stable, but not in-place 