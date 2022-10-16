//Implementation of Stack using LinkedList

#include <iostream>
using namespace std;

class CQueue {
private:
	struct Node {
		int data;
		struct Node* next;
		Node(int newdata, Node* newnext = NULL);
	};
	Node* front, * rear; 

public:
	CQueue();
	void Push(int newdata);
	void Pop();
	void Print();
	int Front();
	int Back();
};

CQueue::Node::Node(int newdata, Node* newnext) {
	data = newdata;
	next = newnext;
}

CQueue::CQueue() {
	front = NULL;
	rear = NULL;
}

//Insert At Head of the Linkedlist
void CQueue::Push(int newdata) {
	Node* newnode = new Node(newdata);

	if (rear == NULL)
	{
		rear = newnode;
		front = newnode;
	}
	else
	{
		rear->next = newnode;//Add new node next to rear
		rear = newnode;//now newnode becomes rear
	}
}

//Delete head of LinkedList
void CQueue::Pop() {
	Node* temp;

	if (front == NULL && rear == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			temp = front;
			front = front->next;
			temp->next = NULL;
			delete temp;
		}
	}
}

void CQueue::Print()
{
	Node* temp;

	if (front == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}

	temp = front;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int CQueue::Front() {

	if (front == NULL) {
		cout << "Queue is empty" << endl;
		return -1;
	}

	return front->data;
}

int CQueue::Back() {

	if (rear == NULL) {
		cout << "Queue is empty" << endl;
		return -1;
	}

	return rear->data;
}



int main() {

	CQueue q;

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Push(6);

	q.Print();

	cout << q.Front() << endl;
	cout << q.Back() << endl;

	q.Pop();

	q.Print();

	return 0;
}








