#include "LinkedList.hpp"


//From MyCodeSchool (YouTube)
//Time Complexity : O(N), Traversing over the linked list of size N.
//Auxiliary Space : O(1)
void Reverse(Node* head) {
	Node* prevNode, * currNode, * nextNode;

	currNode = head;
	prevNode = NULL;
	while (currNode != NULL) {
		nextNode = currNode->next; // Store Current's next in nextNode
		currNode->next = prevNode; // Point the Current's next to Previous
		prevNode = currNode; 	   // Move Previous to Current
		currNode = nextNode; 	   // Move Current to Next
	}

	head = prevNode;
}

//From Abdul Bari (Udemy)
void Reverse2(Node* head)
{
	Node* p, * q, * r;

	p = head; //Current
	q = NULL; //Previous of current
	r = NULL; //Previous of previous of current
	while (p != NULL)
	{
		r = q;       //r became Previous
		q = p;		 //q became Current
		p = p->next; //p became Next
		q->next = r; //Point current's next to Previous
	}
	head = q;
}


//Using Stack
void ReverseUsingStack(Node* head)
{
	if (head == NULL) {
		return;
	}

	stack<Node*> S;
	Node* temp = head;

	while (temp != NULL) {
		S.push(temp);
		temp = temp->next;
	}

	temp = S.top();
	head = temp;
	S.pop();

	while (!S.empty()) {
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}


//Using Recursion
//The idea is to reach the last node of the linked list using recursion then start reversing the linked list.
//https://www.geeksforgeeks.org/reverse-a-linked-list/

Node* ReverseUsingRecursion(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	//Reverse the rest list and put the first element at the end.
	Node* currNode = head;
	Node* tempNode = ReverseUsingRecursion(head->next);
	currNode->next->next = currNode;
	currNode->next = NULL;

	return tempNode;
}


// Using Recursion - Another approach
void ReverseRecUtil1(Node* prevNode, Node* currentNode, Node*& head)
{
	if (currentNode)
	{
		ReverseRecUtil1(currentNode, currentNode->next, head);
		currentNode->next = prevNode;
	}
	else {
		head = prevNode;
	}
}

Node* ReverseUsingRecursion1(Node* head) {
	ReverseRecUtil1(NULL, head, head);
	return head;
}

//Reverse a linked list from position m to n, where 1 =< m =< n =< length
//Do it in-place and in one-pass. 
void ReverseInBetween(Node* head, int m, int n) {
	Node* prevNode, * currNode, * nextNode;

	Node preHead{}; // zero initialization
	preHead.next = head;

	currNode = head;
	prevNode = &preHead;

	int i = 1;
	while (i < n) {
		if (i < m) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		else {
			nextNode = currNode->next;
			currNode->next = nextNode->next;
			nextNode->next = prevNode->next;
			prevNode->next = nextNode;
		}

		i++;
	}

	head = preHead.next;
}
