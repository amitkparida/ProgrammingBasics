
#include<iostream>
using namespace std;

void SelectionSort(int A[], int n) {
	int i, j, minIndex, temp;

	for (i = 0; i < n - 1; i++) {
		minIndex = i;

		for (j = i + 1; j < n; j++) {
			if (A[j] < A[minIndex]) {
				minIndex = j;
			}
		}

		if (i != minIndex) {
			temp = A[i];
			A[i] = A[minIndex];
			A[minIndex] = temp;
		}
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };

	SelectionSort(A, sizeof(A)/sizeof(A[0]));

	for (int i : A) {
		cout << i << " ";
	}
}

//Time Complexity =  O(n) <- Best, O(n^2) <- Worst, Average
//Space Complexity = O(1)

// Slection sort is not adaptive, not stable.
// Bubble and Insertion sorts are adaptive (Adaptive means, if the list is already sorted, the algorithm should take minimum time.)
// Bubble, Insertion and Merge sorts are stable (Stable means, elements with duplicate values don't change their order. Useful for Databases.).
// k no of passes in Selection sort gives you k smallest elements
// k no of passes in Bubble sort gives you k largest elements
// Insertion sort is suitable for LinkedList





