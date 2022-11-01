
// TOPIC: Doubly Linked List

// NOTES:
// 1. Unlike singly linked list, doubly linked list can traverse in both forward and backward direction.
// 2. Doubly linked list requires one more pointer to point at previous node.

// ADVANTAGE:
// 1. DLL can traverse in both direction.

// DISADVATAGE:
// 1. It is more complicated then SLL.
// 2. It takes more space than SLL.

#include <iostream>
using namespace std;

class CDoublyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
		Node(int newdata, Node* newnext = NULL, Node* newprev = NULL);
	};
	Node* head;

public:
	CDoublyLinkedList();
	~CDoublyLinkedList();
	void PushBack(int newdata); //InsertAtTail
	void PushFront(int newdata); //InsertAtHead
	void Print();
	void DeleteNode(int data);
	void DeleteAtPosition(int position);
	void InsertAtPosition(int position, int newdata);
	void DeleteList();
	void Reverse();
	int Length();
};

CDoublyLinkedList::Node::Node(int newdata, Node* newnext, Node* newprev) {
	data = newdata;
	next = newnext;
	prev = newprev;
}

CDoublyLinkedList::CDoublyLinkedList() {
	head = NULL;
}

CDoublyLinkedList::~CDoublyLinkedList() {
	Node* temp = head;
	while (head) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

//InsertAtTail
void CDoublyLinkedList::PushBack(int newdata) {
	Node* newnode = NULL, * temp = NULL;

	newnode = new Node(newdata);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		Node* curr = head;

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		newnode->prev = curr;
		curr->next = newnode;
	}
}

//InsertAtHead
void CDoublyLinkedList::PushFront(int newdata) {
	Node* newnode = NULL;

	newnode = new Node(newdata);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}

void CDoublyLinkedList::Print() {
	Node* temp = head;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;

		if (temp != NULL) {
			cout << " <-> ";
		}
	}
	cout << endl;
}


void CDoublyLinkedList::DeleteNode(int data) {
	Node* temp, * curr, * prev;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	if (head->data == data) {
		temp = head;
		head = head->next;
		head->prev = NULL;
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
			curr->next->prev = prev;
			curr->next = NULL;
			curr->prev = NULL;
			delete curr;
		}

	}
}

void CDoublyLinkedList::DeleteAtPosition(int position) {
	Node* temp, * curr, * previous;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	//deleting first node
	if (position == 1) {
		temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		curr = head;
		previous = head;
		int count = 1;
		while (count < position && curr != NULL) {   //for 0 based index, the condition should be count < index + 1
			previous = curr;
			curr = curr->next;
			count++;
		}

		if (curr == NULL || position < 1) {
			cout << "Position not found" << endl;
		}
		else {
			previous->next = curr->next;
			curr->next->prev = previous;
			curr->next = NULL;
			curr->prev = NULL;
			delete curr;
		}
	}
}


void CDoublyLinkedList::InsertAtPosition(int position, int newdata) {
	Node* newnode, * temp;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	newnode = new Node(newdata);

	if (position == 1)
	{
		newnode->next = head;
		head->prev = newnode;
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
		temp->next->prev = newnode;
		newnode->prev = temp;
		temp->next = newnode;
	}
}


void CDoublyLinkedList::DeleteList() {
	Node* temp = head;

	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}


void CDoublyLinkedList::Reverse() {
	Node * prevNode, * currNode, * nextNode;

	currNode = head;
	prevNode = NULL;

	while (currNode)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		currNode->prev = nextNode;
		prevNode = currNode;
		currNode = nextNode;
	}

	head = prevNode;
}


int CDoublyLinkedList::Length() {
	int length = 0;
	Node* temp = head;
	while (temp != nullptr) {
		length++;
		temp = temp->next;
	}
	return length;
}


int main() {
	CDoublyLinkedList* mylist = new CDoublyLinkedList;

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

	mylist->DeleteList();
	return 0;
}








