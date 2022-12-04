
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