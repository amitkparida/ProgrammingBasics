
#include<iostream>
using namespace std;

void InsertionSort(int A[], int n) {
	int i, val, hole;

	for (i = 1; i < n; i++) { //At the beginning, A[0] is the part of the sorted array
		val = A[i]; //Value to be inserted at appropriate index (hole)

		for (hole = i; hole > 0 && A[hole - 1] > val; hole--) {
			A[hole] = A[hole - 1];
		}

		A[hole] = val;
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };

	InsertionSort(A, sizeof(A) / sizeof(A[0]));

	for (int i : A) {
		cout << i << " ";
	}
}

//Time Complexity = O(n^2) <- Average, Worst, O(n)<- Best
//Space Complexity = O(1)

//The no. of comparisons and shifts/swaps in insertion sort is less in all practical scenarios than in Bubble sort and Selection sort.
//So Insertions sort is better than Bubble sort and Selection sort.
