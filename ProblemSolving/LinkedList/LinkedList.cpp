
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

	Node* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	PushBack(head, 6);
	Print(head);

	//mylist->DeleteNode(200);

	cout << "Middle Node: " << MiddleNode(head)->data << endl;
	FindNthNodeFromEnd(head, 1);
	DeleteNthNodeFromEnd(head, 1);
	Print(head);

	cout << "Sort the list: " << endl;
	MergeSort(head);
	Print(head);
	Print(ReverseUsingRecursion1(head));

	DeleteList(head);

	return 0;
}


//InsertAtTail
Node* PushBack(Node*& head, int data) {
	Node* newnode = NULL, * temp = NULL;

	newnode = new Node(data);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
	}

	return head;
}

void Print(Node* head) {
	Node* temp = head;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;

		if (temp != NULL) {
			cout << " -> ";
		}
	}
	cout << endl;
}

void DeleteList(Node* head) {
	Node* temp = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void MakeLoop(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = head;
			return;
		}
		temp = temp->next;
	}
}

