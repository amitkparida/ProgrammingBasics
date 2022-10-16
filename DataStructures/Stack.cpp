//Implementation of Stack using LinkedList

#include <iostream>
using namespace std;

class CStack {
private:
	struct Node {
		int data;
		struct Node* next;
		Node(int newdata, Node* newnext = NULL);
	};
	Node* top;

public:
	CStack();
	void Push(int newdata);
	void Pop(); 
	void Print();
	int Top();
	void InsertAtBottom(int newdata);
	void Reverse();
};

CStack::Node::Node(int newdata, Node* newnext) {
	data = newdata;
	next = newnext;
}

CStack::CStack() {
	top = NULL;
}

//Insert At Head of the Linkedlist
void CStack::Push(int newdata) {
	Node* newnode = new Node(newdata);

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
		cout << temp->data << " ";
		temp = temp->next;
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








