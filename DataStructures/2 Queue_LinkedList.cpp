//Implementation of Queue using LinkedList

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

class CQueue {
private:
	Node* front, * rear;

public:
	CQueue();
	~CQueue();
	void Push(int newdata);
	void Pop();
	void Print();
	int Front();
	int Back();
};

CQueue::CQueue() {
	front = NULL;
	rear = NULL;
}

CQueue::~CQueue() {
	Node* temp = NULL;
	while (front) {
		temp = front;
		front = front->next;
		delete temp;
	}
}


//Insert At Head of the Linkedlist
void CQueue::Push(int newdata) {
	Node* newnode = new Node(newdata);
	//newnode = new Node;  //If you don't define constructor of the Node structure, you can assign manually like this
	//newnode->data = newdata;
	//newnode->next = NULL;

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

	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		if (front == rear)
		{
			delete front;
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

		if (temp != NULL) {
			cout << " <- ";
		}
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
