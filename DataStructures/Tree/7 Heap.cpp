// What is HEAP (Binary Heap)? 
// It�s a tree like structure with these conditions :
// - Complete binary tree
// - Min heap : Every node should be smaller than the ones below it. So the element at the top (root node) will be the min one.
// - Max heap : Every node should be bigger than the ones below it. So the element at the top (root node) will be the max one.

// Relationship between array indexes and tree element in Heap / Complete Binary Tree:
// - An array can be used to store the nodes of a Heap in the following way.
// - If the index of any element in the array is i, the element in the index 2i + 1 will become the left child 
//   and element in 2i + 2 index will become the right child.
// - Also, the parent of any element at index i is given by the lower bound of (i - 1) / 2.

// What is PRIORITY QUEUE?
// It�s a binary heap based structure where we can sort and store elements in max/min fashion so that every time we need 
// the largest/smallest element, we just pop it off from the top instead of sorting and computing the whole thing again.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
private:
	std::vector<int> arr; // Array to store heap.
	int(*compare)(int, int);
	int length = 0;

public:
	Heap(int(*comp)(int, int));
	Heap(std::vector<int>& array_in, int(*comp)(int, int));
	void add(int value);
	int remove();
	int peek();
	void print();
	int size();
	bool isEmpty();
	bool deleteValue(int value);

private:
	void proclateDown(int position);
	void proclateUp(int position);
	void doubleSize();
};


Heap::Heap(int(*comp)(int, int)) {
	arr = std::vector<int>(100); // Initial array size 100
	compare = comp;
}

Heap::Heap(std::vector<int>& array, int(*comp)(int, int)) {
	arr = array;
	compare = comp;
	length = array.size();
	// Build Heap operation over array
	for (int i = (length / 2); i >= 0; i--) {
		proclateDown(i);
	}
}

void Heap::proclateDown(int parent) {
	int lChild = 2 * parent + 1;
	int rChild = lChild + 1;
	int child = -1;

	if (lChild < length) {
		child = lChild;
	}

	if (rChild < length && compare(arr[lChild], arr[rChild])) {
		child = rChild;
	}

	if (child != -1 && compare(arr[parent], arr[child])) {
		int temp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = temp;
		proclateDown(child);
	}
}

void Heap::proclateUp(int child) {
	int parent = (child - 1) / 2;
	if (parent < 0) {
		return;
	}

	if (compare(arr[parent], arr[child])) {
		int temp = arr[child];
		arr[child] = arr[parent];
		arr[parent] = temp;
		proclateUp(parent);
	}
}

void Heap::add(int value) {
	if (length == arr.size()) {
		doubleSize();
	}

	arr[length++] = value;
	proclateUp(length - 1);
}

void Heap::doubleSize() {
	std::vector<int> old = arr;
	arr = std::vector<int>(arr.size() * 2);
	for (int i = 0; i < length; i++) {
		arr[i] = old[i];
	}
}

int Heap::remove() {
	if (isEmpty())
		throw "HeapEmptyException.";

	int value = arr[0];
	arr[0] = arr[length - 1];
	length--;
	proclateDown(0);
	return value;
}

void Heap::print() {
	std::cout << "Heap :: ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

bool Heap::isEmpty() {
	return (length == 0);
}

int Heap::size() {
	return length;
}

int Heap::peek() {
	if (isEmpty())
		throw "Heap empty exception.";

	return arr[0];
}

bool Heap::deleteValue(int value) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == value) {
			arr[i] = arr[length - 1];
			length -= 1;
			proclateUp(i);
			proclateDown(i);
			return true;
		}
	}
	return false;
}

// min heap compare function.
int Greater(int a, int b) {
	return a > b;
}

// max heap compare function.
int Less(int a, int b) {
	return a < b;
}

void heapSort(std::vector<int>& array, bool inc) {
	// min heap for decreasing and max heap for increasing.
	Heap hp = Heap(array, (inc) ? Less : Greater);
	int length = array.size();
	for (int i = length - 1; i >= 0; i--)
		array[i] = hp.remove();
}


// Testing code.
int main1() {
	Heap hp = Heap(Greater);
	hp.add(1);
	hp.add(9);
	hp.add(6);
	hp.add(7);
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}

/*
Heap :: 1 7 6 9
1 6 7 9
 */

 // Testing code.
int main2() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, Greater); // Min Heap
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
Heap :: 0 1 2 4 5 3
0 1 2 3 4 5
 */

 // Testing code.
int main3() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, Less); // Max Heap
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
Heap :: 5 4 3 1 0 2
5 4 3 2 1 0
 */

// Testing code.
int main4() {
	std::vector<int> a = { 1, 9, 6, 7, 8, 10, 2, 4, 5, 3 };
	heapSort(a, true);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
*/

// Testing code.
int main5() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, Greater); // Min Heap
	hp.print();
	hp.deleteValue(3);
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}

int main() 
{
	main1();
	main2();
	main3();
	main4();
	main5();
}