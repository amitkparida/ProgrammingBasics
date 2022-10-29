#include <iostream>
using namespace std;

int main()
{
	//Normal Declaration. Completely in Stack
	int A[3][4] = { {1,2,3,4},{2,4,6,8},{1,3,5,7} };

	//Array Of Pointers. Partially in Stack, partially in Heap.
	int* B[3];
	B[0] = new int[4];
	B[1] = new int[4];
	B[2] = new int[4];

	// Double Pointer. Almost everything is inside heap.
	int** C;
	C = new int* [3];
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int A[3][4] = { {1,2,3,4},{2,4,6,8},{1,3,5,7} };
//
//	int* B[3];
//	B[0] = (int*)malloc(4 * sizeof(int));
//	B[1] = (int*)malloc(4 * sizeof(int));
//	B[2] = (int*)malloc(4 * sizeof(int));
//
//	int** C;
//	C = (int**)malloc(3 * sizeof(int*));
//	C[0] = (int*)malloc(4 * sizeof(int));
//	C[1] = (int*)malloc(4 * sizeof(int));
//	C[2] = (int*)malloc(4 * sizeof(int));
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++) 
//		{
//			printf("%d ", C[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


