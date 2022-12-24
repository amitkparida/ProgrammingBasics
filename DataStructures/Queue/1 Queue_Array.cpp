//Implementation of Queue using Array

#include <iostream>
using namespace std;

class CQueue {
private:
	int* arr;
	int front;
	int rear;
	int capacity;

public:
	CQueue(int size = 100);
	~CQueue();
	void Push(int data);
	void Pop();
	int Front();
	int Back();
	void Print();
	int Size();
	bool IsEmpty();
};

CQueue::CQueue(int size) {
	capacity = size;
	arr = new int[capacity];
	front = -1;
	rear = -1;
}

CQueue::~CQueue() {
	delete[] arr;
}

void CQueue::Push(int data) {
	if (rear == capacity - 1) {
		cout << "Queue is full" << endl;
		return;
	}

	if (front == -1 && rear == -1)
	{
		front = rear = 0;
	}
	else
	{
		rear++;
	}

	arr[rear] = data;
}

void CQueue::Pop() {
	if (front == -1 || front > rear) {
		cout << "Queue is empty" << endl;
		return;
	}

	if (front == 0 && rear == 0) //In case of single element
	{
		front = rear = -1;
	}
	else
	{
		front++;
	}
}

int CQueue::Front() {
	if (front == -1 || front > rear) {
		cout << "Queue is empty" << endl;
		return -1;
	}

	return arr[front];
}

int CQueue::Back() {
	if (front == -1 || front > rear) {
		cout << "Queue is empty" << endl;
		return -1;
	}

	return arr[rear];
}


void CQueue::Print() {
	if (front == -1 || front > rear) {
		cout << "Queue is empty" << endl;
		return;
	}

	for (int i = front; i <= rear; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int CQueue::Size() {
	return rear + 1;
}

bool CQueue::IsEmpty() {
	return (rear == -1);
}

int main() {
	CQueue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Print();
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Pop();
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	return 0;
}




