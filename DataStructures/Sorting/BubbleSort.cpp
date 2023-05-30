
// Push the maximum to the last by adjacent swaps

// https://takeuforward.org/data-structure/bubble-sort-algorithm/

#include<iostream>
using namespace std;

void BubbleSort(int A[], int n) {
	int pass, i, temp;

	bool bSwapped = false;

	for (pass = 0; pass < n - 1; pass++) {
		bSwapped = false;

		for (i = 0; i < n - 1 - pass; i++) {
			if (A[i] > A[i + 1]) {
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;

				bSwapped = true;
			}
		}

		if (bSwapped == false) {
			break; //breaks the outer for loop
		}
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };

	BubbleSort(A, sizeof(A) / sizeof(A[0]));

	for (int i : A) {
		cout << i << " ";
	}
}

//Time Complexity
// O(n^2) <- Average, Worst, 
// O(n) <- Best 

//Space Complexity = O(1)



// SUMMARY ABOUT ALL SORTING ALGORITHMS:

// The no. of comparisons and shifts/swaps in insertion sort is less in all practical scenarios than in Bubble sort and Selection sort. So Insertions sort is better than Bubble sort and Selection sort.
// Insertion sort is online, i.e., if the input array size is not fixed, and can increase with time, you can use Insertion sort.

// Bubble and Insertion sorts are adaptive (Adaptive means, if the list is already sorted, the algorithm should take minimum time.)
// Bubble, Insertion and Merge sorts are stable (Stable means, elements with duplicate values don't change their order. Useful for Databases.).
// Selection sort is not adaptive, not stable.
// Merge sort is stable, but not in-place .
// Merge sort is suitable for LinkedList. Quick sort is for arrays.
// k no of passes in Selection sort gives you k smallest elements
// k no of passes in Bubble sort gives you k largest elements

// Idea behind Quick Sort :
// An element is in sorted position if all the elements before it are smaller than it and all the elements after it are larger than it.
// Quick sort does not mean it is the fastest sort.

// In Selection sort, we select the position and find out an element for that position. But in Quick sort we select an element and find out a position for that element.

// Quick sort is also called Selection Exchange sort or Partition Exchange sort

