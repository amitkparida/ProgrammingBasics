
#include "LinkedList.h"



/*
 To Implement:

 Karun and Kapil
================
5. Add two numbers
6. Add two numbers II
10. Palindrome Linked List *
12. Swapping nodes in Linked List
13. Odd Even Linked List
14. Swap Nodes in Pairs
15. Copy list with Random Pointer
16. Reverse Nodes in K-group

Kapil:
======
6. Convert Binary Number in a Linked List to Integer
21. Split Linked List in Parts
22. Merge k Sorted Lists

Striver: (A to Z)
========
Length of Loop in LL
Sort a LL of 0’s 1’s and 2’s by changing links
Add 1 to a number represented by LL
Delete all occurrences of a key in DLL
Find pairs with given sum in DLL
Rotate a LL
Flattening of LL

*/

int main() {
	CLinkedList mylist;

	mylist.PushBack(1);
	mylist.PushBack(2);
	mylist.PushBack(3);
	mylist.PushBack(4);
	mylist.PushBack(5);
	mylist.PushBack(6);
	mylist.Print();

	//mylist->DeleteNode(200);

	cout << "Middle Node: " << mylist.MiddleNode()->data << endl;
	mylist.FindNthNodeFromEnd(1);
	mylist.DeleteNthNodeFromEnd(1);
	mylist.Print();

	cout << "Sort the list: " << endl;
	mylist.Sort();
	mylist.Print();

	//mylist->DeleteList();

	return 0;
}