// Linked List

// NOTES:
// 1. This is a sequencial data structure and is used to store data.
// 2. Linked list is special data structure in which data elements are linked to one another.
// 3. The pictorial look of a linked list is:

// OPERATIONS:
// Insertion, Deletion, Traversing.

// PROS
// 1. Linked list is dynamic data structure, it can grow and shrink at run time.
// 2. It is used to efficiently utilize memory
// 3. Insertion and Deletion is very easy at any position.

// CONS
// 1. More memory is required if list is too big.
// 2. Accessing elements is time consuming.

// TYPES OF LINKED LIST:
// 1. Singly Linked List
// 2. Doubly Linked List
// 3. Circular Linked List
// 4. Doubly Circular Linked List


// You can read more problems here 
// https://github.com/loveBabbar/CodeHelp-DSA-Busted-Series/blob/main/Lecture044%20Linked%20List%20Day1/singlyLinkedList.cpp
// https://github.com/Hemant-Jain-Author/Problem-Solving-in-Data-Structures-and-Algorithms-using-Cpp/blob/master/LinkedList/LinkedList.cpp
// https://github.com/cppnuts-yt/CppNuts
// https://github.com/coding-minutes/dsa-essentials-course
// https://leetcode.com/problems/add-two-numbers/discuss/1340/a-summary-about-how-to-solve-linked-list-problem-c


#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

class CLinkedList{
private:
	Node* head;

public:
	CLinkedList();
	~CLinkedList();
	void PushBack(int newdata); //InsertAtTail
	void PushFront(int newdata); //InsertAtHead
	void Print();
	void DeleteNode(int data);
	void DeleteAtPosition(int position);
	void InsertAtPosition(int position, int newdata);
	int Length();
	void DeleteList();
	void Reverse();
	void Reverse2();
	void ReverseUsingStack();
	void ReverseUsingRecursion();
	void ReverseInBetween(int left, int right);

private:
	void ReverseRecUtil(Node* prevNode, Node* currentNode);
};

CLinkedList::CLinkedList() {
	head = NULL;
}

CLinkedList::~CLinkedList()
{
	Node* temp = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	//Node* temp = head;
	//while (head)
	//{
	//	head = head->next;
	//	delete temp;
	//	temp = head;
	//}
}

//InsertAtTail
void CLinkedList::PushBack(int newdata) { 
	Node *newnode = NULL, *temp = NULL;

	newnode = new Node(newdata);

	//newnode = new Node;  //If you don't define constructor of the Node structure, you can assign manually like this
	//newnode->data = newdata; 
	//newnode->next = NULL;

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
}

//InsertAtHead
void CLinkedList::PushFront(int newdata) {
	Node* newnode = NULL;

	newnode = new Node(newdata);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}

void CLinkedList::Print() {
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


void CLinkedList::DeleteNode(int data) {
	Node* temp, * curr, * prev;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	if (head->data == data) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else {
		curr = head;
		prev = head; //to avoid warning
		while (curr != NULL && curr->data != data) {
			prev = curr;
			curr = curr->next;
		}

		if (curr == NULL) {
			cout << "Data is not present" << endl;

		}
		else {
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
		}

	}
}

void CLinkedList::DeleteAtPosition(int position) {
	Node* temp, * curr, * prev;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	//deleting first node
	if (position == 1) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		//deleting any middle node or last node
		curr = head;
		prev = head;
		int count = 1;
		while (count < position && curr != NULL) {   //for 0 based index, the condition should be count < index + 1
			prev = curr;
			curr = curr->next;
			count++;
		}

		if (curr == NULL || position < 1) {
			cout << "Position not found" << endl;
		}
		else {
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
		}
	}
}

void CLinkedList::InsertAtPosition(int position, int newdata) {
	Node *newnode, *temp;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	newnode = new Node(newdata);

	if (position == 1)
	{
		newnode->next = head;
		head = newnode;
		return;
	}

	temp = head;
	for (int i = 1; i < (position - 1) && temp != NULL; i++)  ////for 0 based index, the condition should be count < index
	{
		temp = temp->next;
	}

	if (temp == NULL || position < 1)
	{
		cout << "Position not found" << endl;
	}
	else
	{
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

int CLinkedList::Length()
{
	Node* temp = head;
	int len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return len;
}


void CLinkedList::DeleteList() {
	Node* temp = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

//From MyCodeSchool (YouTube)
void CLinkedList::Reverse() {
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
void CLinkedList::Reverse2()
{
	Node * p, * q , * r;

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
void CLinkedList::ReverseUsingStack()
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
void CLinkedList::ReverseUsingRecursion() {
	ReverseRecUtil(NULL, head);
}
void CLinkedList::ReverseRecUtil(Node* prevNode, Node* currentNode)
{
	if (currentNode)
	{
		ReverseRecUtil(currentNode, currentNode->next);
		currentNode->next = prevNode;
	}
	else {
		head = prevNode;
	}
}

//Reverse a linked list from position m to n, where 1 =< m =< n =< length
//Do it in-place and in one-pass. 
void CLinkedList::ReverseInBetween(int m, int n) {
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

int main() {
	CLinkedList* mylist = new CLinkedList;

	mylist->PushBack(1);
	mylist->PushBack(2);
	mylist->PushBack(3);
	mylist->PushBack(4);
	mylist->PushBack(5);
	mylist->PushBack(6);
	mylist->Print();

	mylist->InsertAtPosition(3, 100);
	mylist->Print();

	mylist->DeleteAtPosition(3);
	mylist->Print();

	mylist->PushFront(200);
	mylist->Print();

	//mylist->DeleteNode(200);
	mylist->Reverse();
	mylist->Print();

	mylist->ReverseInBetween(2, 5);
	mylist->Print();

	//mylist->DeleteList();

	delete mylist;

	return 0;
}








