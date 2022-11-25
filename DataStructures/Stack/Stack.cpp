
//Implementation of Stack using LinkedList

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

class CStack {
private:
	Node* top;

public:
	CStack();
	~CStack();
	void Push(int newdata);
	void Pop(); 
	void Print();
	int Top();
	void InsertAtBottom(int newdata);
	void Reverse();
};

CStack::CStack() {
	top = NULL;
}

CStack::~CStack() {
	Node* temp = NULL;
	while (top) {
		temp = top;
		top = top->next;
		delete temp;
	}
}

//Insert At Head of the Linkedlist
void CStack::Push(int newdata) {
	Node* newnode = new Node(newdata);
	//newnode = new Node;  //If you don't define constructor of the Node structure, you can assign manually like this
	//newnode->data = newdata; 
	//newnode->next = NULL;

	if (top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->next = top; 
		top = newnode;
	}
}

//Delete head of LinkedList
void CStack::Pop() {
	Node* temp;

	if (top == NULL) {
		cout << "Stack is empty" << endl;
		return;
	}

	temp = top;
	top = top->next;
	temp->next = NULL;
	delete temp;
}

void CStack::Print()
{
	Node* temp;

	if (top == NULL) {
		cout << "Stack is empty" << endl;
		return;
	}

	temp = top;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;

		if (temp != NULL) {
			cout << " -> ";
		}
	}
	cout << endl;
}

int CStack::Top() {

	if (top == NULL) {
		cout << "Stack is empty" << endl;
		return -1;
	}

	return top->data;
}

void CStack::Reverse() {
	if (top == NULL) {
		return;
	}

	int t = Top();
	Pop();
	Reverse();
	InsertAtBottom(t);
}

void CStack::InsertAtBottom(int newdata) {

	Node* newnode = new Node(newdata);

	if (top == NULL)
	{
		Push(newdata);
	}
	else
	{
		int temp = Top();
		Pop();
		InsertAtBottom(newdata);
		Push(temp);
	}
}


int main() {
	CStack st;

	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Push(6);

	st.Print();

	cout << st.Top() << endl;

	st.InsertAtBottom(100);

	st.Print();

	st.Reverse();
	st.Print();

	return 0;
}




/*
//Implement Using dynamic Array
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
*/