
//Implement Stack Using dynamic Array

#include <iostream>
using namespace std;

class CStack {
private:
	int* arr;
	int top;
	int capacity;

public:
	CStack(int size = 100);
	~CStack();
	void Push(int data);
	void Pop();
	int Top();
	void Print();
	int Size();
	bool IsEmpty();
};

CStack::CStack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}

CStack::~CStack() {
	delete[] arr;
}

void CStack::Push(int data) {
	if (top == capacity - 1) {
		cout << "Stack OverFlow" << endl;
		return;
	}
	top++;
	arr[top] = data;
}

void CStack::Pop() {
	if (top == -1) {
		cout << "Stack Underflow" << endl;
		return;
	}

	top--;
}

int CStack::Top() {
	if (top == -1) {
		cout << "Stack Underflow" << endl;
		return -1;
	}
	return arr[top];
}

void CStack::Print() {

	if (top == -1) {
		cout << "Stack Underflow" << endl;
		return;
	}

	for (int i = top; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int CStack::Size() {
	return top + 1;
}

bool CStack::IsEmpty() {
	return (top == -1);
}

int main() {
	CStack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Print();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	return 0;
}
