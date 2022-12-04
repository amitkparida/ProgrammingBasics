
//Idea behind Quick Sort :
//An element is in sorted position if all the elements before it are smaller than it and all the elements after it are larger than it.
//Quick sort does not mean it is the fastest sort.

//Worst case: If the input list is sorted in ascending/descending order and partitioning is always done at either left most element or right most element, 
//quick sort time complexity will become worst case i.e. O(n^2)

//Best case: For sorted/unsorted input, if partitioning is always done in the middle of the the array, 
//quick sort time complexity will be Best case i.e. O(nlogn)

//Average case: O(nlogn)

//Time Complexity 
//O(nlogn) <- Average, Best, 
//O(n^2) <- Worst 

//Space Complexity = O(logn)

//In Selection sort, we select the position and find out an element for that position. But in Quick sort we select an element and find out a postion for that element.

// Quick sort is also called Selection Exchange sort or Partition Exchange sort


#include <iostream>
using namespace std;

void Print(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];

        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int Partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low ;
    int j = high;

    while (i < j) {
        // Increment i as long as elements are smaller/equal to pivot
        while (A[i] <= pivot && i < j) {
            i++;
        }

        // Decrement j as long as elements are larger than pivot
        while (A[j] > pivot && j >= i) {
            j--;
        }

        if (i < j) {
            Swap(A[i], A[j]);
        }
    }

    Swap(A[low], A[j]);
    return j;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = Partition(A, low, high); // A[pivot] in sorted position
        QuickSort(A, low, pivot - 1); // Sort elements in range: A[low], A[pivot-1]
        QuickSort(A, pivot + 1, high); // Sort elements in range: A[pivot+1], A[high]
    }
}

int main() {
    cout << "First Element as Pivot" << endl;
    int A[] = { 11, 13, 7, 12, 16, 9, 24, 5, 10, 3 };
    int n = sizeof(A) / sizeof(A[0]);

    cout << "A: ";
    Print(A, n);
    
    QuickSort(A, 0, n - 1);

    cout << "Sorted A: ";
    Print(A, n);

    return 0;
}




