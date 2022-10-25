

// You can read more problems here 
// https://github.com/loveBabbar/CodeHelp-DSA-Busted-Series/blob/main/Lecture044%20Linked%20List%20Day1/singlyLinkedList.cpp
// https://github.com/Hemant-Jain-Author/Problem-Solving-in-Data-Structures-and-Algorithms-using-Cpp/blob/master/LinkedList/LinkedList.cpp
// https://github.com/coding-minutes/data-structures-algorithms-level-up-bootcamp/blob/master/07%20Linked%20Lists/linked_list.cpp

#include <iostream>
#include <stack>
using namespace std;

class CLinkedList{
private:
	struct Node {
		int data;
		Node* next;
		Node(int newdata, Node* newnext = NULL);
	};
	Node* head;

public:
	CLinkedList();
	void PushBack(int newdata); //InsertAtTail
	void PushFront(int newdata); //InsertAtHead
	void Print();
	void DeleteNode(int data);
	void DeleteAtPosition(int position);
	void InsertAtPosition(int position, int newdata);
	void DeleteList();
	void Reverse();
	void ReverseUsingRecursion();
	Node* ReverseRecUtil(Node* currentNode, Node* nextNode);
	void ReverseUsingStack();
};

CLinkedList::Node::Node(int newdata, Node* newnext) {
	data = newdata;
	next = newnext;
}

CLinkedList::CLinkedList() {
	head = NULL;
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


void CLinkedList::DeleteList() {
	Node* curr = head;
	Node* next;

	while (curr != NULL) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	head = NULL;
}


void CLinkedList::Reverse() {
	Node* prev, * current, * temp;

	current = head;
	prev = NULL;
	while (current != NULL) {
		//store next
		temp = current->next;
		//update the current
		current->next = prev;
		//prev and current
		prev = current;
		current = temp;
	}

	head = prev;
	return;
}


//Using recursion
void CLinkedList::ReverseUsingRecursion() {
	head = ReverseRecUtil(head, NULL);
}

CLinkedList::Node* CLinkedList::ReverseRecUtil(Node* currentNode,Node* nextNode) {
	Node* ret;
	if (currentNode == NULL) {
		return NULL;
	}
	if (currentNode->next == NULL) {
		currentNode->next = nextNode;
		return currentNode;
	}

	ret = ReverseRecUtil(currentNode->next, currentNode);
	currentNode->next = nextNode;
	return ret;
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
	mylist->ReverseUsingStack();
	mylist->Print();

	mylist->DeleteList();
	return 0;
}








