// TOPIC: Cicular Doubly Linked List

// NOTES:
// 1. This is combination of CLL and DLL.

// ADVANTAGE :
// 1. List can be traversed from both the directions i.e.from head to tail or from tail to head.
// 2. Jumping from head to tail or from tail to head is done in constant time O(1).
// 3. Circular Doubly Linked Lists are used for implementation of advanced data structures like Fibonacci Heap.

// DISADVANTAGE :
// 1. It takes extra memory in each node to accommodate previous pointer.
// 2. Lots of pointers involved while implementing or doing operations on a list.


#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node() : data(0), next(this), prev(this) {}
	Node(int x) : data(x), next(this), prev(this) {}
	Node(int x, Node* next, Node* prev) : data(x), next(next), prev(prev) {}
};

class DoublyCircularLinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int length = 0;

public:
	DoublyCircularLinkedList();
	~DoublyCircularLinkedList();
	virtual int size();
	virtual bool isEmpty();
	virtual void addHead(int value);
	virtual int removeHead();

	virtual int peekHead();
	virtual void addTail(int value);
	virtual int removeTail();
	virtual bool find(int key);
	virtual void freeList();
	virtual void print();
};

DoublyCircularLinkedList::DoublyCircularLinkedList() {
	head = nullptr;
	length = 0;
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
	if (head != nullptr) {
		Node* curr = head->next;
		Node* next;
		while (curr != head) {
			next = curr->next;
			delete curr;
			curr = next;
		}
		delete head;
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
}

int DoublyCircularLinkedList::size() {
	return length;
}

bool DoublyCircularLinkedList::isEmpty() {
	return length == 0;
}

int DoublyCircularLinkedList::peekHead() {
	if (isEmpty()) {
		throw("EmptyListException");
	}
	return head->data;
}

void DoublyCircularLinkedList::addHead(int value) {
	Node* newNode = new Node(value);
	if (length == 0) {
		tail = head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev = newNode;
		newNode->prev->next = newNode;
		head = newNode;
	}
	length++;
}

void DoublyCircularLinkedList::addTail(int value) {
	Node* newNode = new Node(value);
	if (length == 0) {
		head = tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		newNode->next = tail->next;
		newNode->prev = tail;
		tail->next = newNode;
		newNode->next->prev = newNode;
		tail = newNode;
	}
	length++;
}

int DoublyCircularLinkedList::removeHead() {
	if (length == 0)
		throw("EmptyListException");

	int value = head->data;
	length--;

	if (length == 0) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return value;
	}

	Node* next = head->next;
	next->prev = tail;
	tail->next = next;
	delete head;
	head = next;
	return value;
}

int DoublyCircularLinkedList::removeTail() {
	if (length == 0)
		throw("EmptyListException");

	int value = tail->data;
	length--;

	if (length == 0) {
		delete tail;
		head = tail = nullptr;
		return value;
	}

	Node* prev = tail->prev;
	prev->next = head;
	head->prev = prev;
	delete tail;
	tail = prev;
	return value;
}

bool DoublyCircularLinkedList::find(int key) {
	Node* temp = head;
	if (head == nullptr)
		return false;

	do {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	} while (temp != head);

	return false;
}

void DoublyCircularLinkedList::freeList() {
	if (head == nullptr)
		return;

	Node* curr = head->next;
	Node* next;
	while (curr != head) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	length = 0;
}

void DoublyCircularLinkedList::print() {
	if (isEmpty())
		return;

	Node* temp = head;
	do {
		std::cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);

	std::cout << std::endl;
}


int main() {
	DoublyCircularLinkedList ll;
	ll.addHead(1);
	ll.addHead(2);
	ll.addHead(3);
	ll.print();
	std::cout << "size : " << ll.size() << std::endl;
	std::cout << "isEmpty : " << ll.isEmpty() << std::endl;
	std::cout << "peek : " << ll.peekHead() << std::endl;

	return 0;
}
