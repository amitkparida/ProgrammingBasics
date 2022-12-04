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
#include <unordered_set>
#include <map>
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
	void SortedInsert(int newdata);
	int Length();
	void DeleteList();
	void Reverse();
	void Reverse2();
	void ReverseUsingStack();
	void ReverseUsingRecursion();
	void ReverseUsingRecursion2();
	void ReverseInBetween(int left, int right);
	Node* MiddleNode();
	Node* MiddleNode2();
	bool IsCircularList();
	bool DetectLoop();
	bool DetectLoop2();
	bool DetectLoop3();
	void RemoveLoop();
	void RemoveLoop2();
	void RemoveDuplicates();
	Node* FindNthNodeFromEnd(int n);
	void DeleteNthNodeFromEnd(int n);

private:
	void ReverseRecUtil(Node* prevNode, Node* currentNode);
	Node* ReverseRecUtil2(Node* head);
	Node* DetectLoopPoint();
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


void CLinkedList::SortedInsert(int newdata) {
	Node* newnode = new Node(newdata);

	if (head == NULL || head->data > newdata) {
		newnode->next = head;
		head = newnode;
		return;
	}

	Node* curr = head;
	while (curr->next != NULL && curr->next->data < newdata) {
		curr = curr->next;
	}

	newnode->next = curr->next;
	curr->next = newnode;
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

//Using Recursion, another approach
void CLinkedList::ReverseUsingRecursion2() {
	head = ReverseRecUtil2(head);
}
Node* CLinkedList::ReverseRecUtil2(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* currNode = head;
	Node* tempNode = ReverseRecUtil2(head->next);
	currNode->next->next = currNode;
	currNode->next = NULL;

	return tempNode;
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


//Find the middle node using 2 traversals
Node* CLinkedList::MiddleNode() {
	Node* temp = head;
	int length = 0;

	while (temp)
	{
		length++;
		temp = temp->next;
	}

	int mid = (length / 2) + 1;

	temp = head;
	for (int i = 1; i < mid; i++) {
		temp = temp->next;
	}

	return temp;
}

//Find the middle node using 2 pointers approach
Node* CLinkedList::MiddleNode2() {
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


// Check if a Linked List is a Circular Linked List
bool CLinkedList::IsCircularList() {
	if (head == NULL) {
		return false;
	}

	Node* temp = head;
	while (temp != NULL) {
		if (temp->next == head) {
			return true;
		}

		temp = temp->next;
	}

	return false;
}


// Find if the list contains a Loop or cycle
bool CLinkedList::DetectLoop() {
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return true;
		}
	}

	return false;
}

bool CLinkedList::DetectLoop2() {
	map<Node*, bool> visited;

	Node* temp = head;
	while (temp) {
		if (visited[temp] == true) {
			return true;
		}

		visited[temp] = true;
		temp = temp->next;

	}

	return false;
}

bool CLinkedList::DetectLoop3() {
	unordered_set<Node*> s;

	Node* temp = head;
	while (temp) {
		if (s.count(temp) > 0) {
			return true;
		}

		s.insert(temp);
		temp = temp->next;
	}

	return false;
}


Node* CLinkedList::DetectLoopPoint() {
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return slow;
		}
	}

	return NULL;
}

void CLinkedList::RemoveLoop() {
	Node* loopPoint = DetectLoopPoint();
	if (loopPoint == NULL) {
		return;
	}

	Node* firstPtr = head;
	if (loopPoint == head) {
		while (firstPtr->next != head) {
			firstPtr = firstPtr->next;
		}
		firstPtr->next = NULL;
		return;
	}

	Node* secondPtr = loopPoint;
	while (firstPtr->next != secondPtr->next) {
		firstPtr = firstPtr->next;
		secondPtr = secondPtr->next;
	}
	secondPtr->next = NULL;
}

void CLinkedList::RemoveLoop2() {
	map<Node*, bool> visited;
	Node* prev = head;
	Node* temp = head;
	while (temp) {
		if (visited[temp] == false) { //If not visited, mark the node as visited
			visited[temp] = true;
			prev = temp;
			temp = temp->next;
		}
		else {
			// If node is already visited, then Loop detected. Make the previous node's next pointer NULL to remove the loop
			prev->next = NULL;
			return;
		}
	}
	return;

	////Using set
	//unordered_set<Node*> s;
	//Node* prev = head;
	//Node* temp = head;

	//while (temp) {
	//	// if node not present in the set, insert it in the set
	//	if (s.count(temp) == 0) {	// if (s.find(temp) == s.end())
	//		s.insert(temp);
	//		prev = temp;
	//		temp = temp->next;
	//	}
	//	else { // if present, it is a cycle, make the previous node's next pointer NULL
	//		prev->next = NULL;
	//		return;
	//	}
	//}
	//return;
}


//Remove duplicates from a sorted list.
void CLinkedList::RemoveDuplicates() {
	Node* curr = head;
	Node* temp = NULL;
	while (curr != NULL && curr->next != NULL) {
		if (curr->data == curr->next->data) {
			temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		else {
			curr = curr->next;
		}
	}
}


Node* CLinkedList::FindNthNodeFromEnd(int n)
{
	// create two pointers currPtr and refPtr initially pointing to head.
	Node* currPtr = head;
	Node* refPtr = head;

	if (head == NULL || n < 1) {
		return NULL;
	}

	// move refPtr to the n-th node from beginning.
	for (int i = 1; i <= n; i++) {
		if (refPtr == NULL) {
			cout << n << " is greater than no. of nodes in the list" << endl;
			return NULL;
		}

		refPtr = refPtr->next;
	}

	// Move both refPtr and currPtr forward until refPtr reaches end of the list.
	while (refPtr != NULL) {
		refPtr = refPtr->next;
		currPtr = currPtr->next;
	}
	cout << "Node no. " << n << " from end is: " << currPtr->data << endl;

	return currPtr;
}


// Function to delete the nth node from the end.
void CLinkedList::DeleteNthNodeFromEnd(int n)
{
	Node* refPtr = head;
	Node* currPtr = head;

	if (head == NULL) {
		return;
	}

	for (int i = 1; i <= n; i++) {
		refPtr = refPtr->next;
	}

	if (refPtr == NULL) {
		head = head->next;
		return;
	}

	while (refPtr->next != NULL) {
		refPtr = refPtr->next;
		currPtr = currPtr->next;
	}
	currPtr->next = currPtr->next->next;
	return;
}


//Merge Two sorted linked lists.
Node* MergeTwoLists(Node* list1, Node* list2) {
	if (list1 == NULL) {
		return list2;
	}

	if (list2 == NULL) {
		return list1;
	}

	Node* resultList = new Node();
	Node* temp = resultList;

	while (list1 != NULL && list2 != NULL) {
		if (list1->data <= list2->data) {
			temp->next = list1;
			list1 = list1->next;
		}
		else {
			temp->next = list2;
			list2 = list2->next;
		}

		temp = temp->next;
	}

	temp->next = (list1 != NULL) ? list1 : list2;

	return resultList->next;
}

//Merge Two sorted linked lists using Recursion
Node* MergeTwoListsRecursion(Node* list1, Node* list2) {
	if (list1 == NULL) {
		return list2;
	}

	if (list2 == NULL) {
		return list1;
	}

	if (list1->data < list2->data) {
		list1->next = MergeTwoListsRecursion(list1->next, list2);
		return list1;
	}
	else {
		list2->next = MergeTwoListsRecursion(list1, list2->next);
		return list2;
	}
}




//Find the intersection point of two linked list

/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
Node* FindIntersectionUtil(int diff, Node* head1, Node* head2)
{
	// Stand at the starting of the bigger list
	Node* current1 = head1;
	Node* current2 = head2;

	// Move the pointer forward by diff nodes
	for (int i = 0; i < diff; i++) {
		if (current1 == NULL) {
			return NULL;
		}

		current1 = current1->next;
	}

	// Move both pointers of both list till they intersect with each other
	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2) {
			return current1;
		}

		current1 = current1->next;
		current2 = current2->next;
	}

	return NULL;
}

Node* FindIntersection(Node* head1, Node* head2) {
	// Count the number of nodes in both the linked lists
	int count1 = 0;
	int count2 = 0;

	Node* temp = head1;
	while (temp != nullptr) {
		count1++;
		temp = temp->next;
	}

	temp = head2;
	while (temp != nullptr) {
		count2++;
		temp = temp->next;
	}

	int diff;

	// If first is greater
	if (count1 > count2) {
		diff = count1 - count2;
		return FindIntersectionUtil(diff, head1, head2);
	}
	else {
		diff = count2 - count1;
		return FindIntersectionUtil(diff, head2, head1);
	}
}




//Merge sort of Linked List

Node* Merge(Node* list1, Node* list2) {

	if (list1 == NULL)
		return list2;

	if (list2 == NULL)
		return list1;

	Node* resultList = new Node();
	Node* temp = resultList;

	//merge 2 sorted Linked List
	while (list1 != NULL && list2 != NULL) {
		if (list1->data < list2->data) {
			temp->next = list1;
			temp = list1;
			list1 = list1->next;
		}
		else
		{
			temp->next = list2;
			temp = list2;
			list2 = list2->next;
		}
	}

	while (list1 != NULL) {
		temp->next = list1;
		temp = list1;
		list1 = list1->next;
	}

	while (list2 != NULL) {
		temp->next = list2;
		temp = list2;
		list2 = list2->next;
	}

	resultList = resultList->next;
	return resultList;
}

Node* FindMid(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

Node* MergeSort(Node* head) {
	//base case
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// break linked list into 2 halvs, after finding mid
	Node* mid = FindMid(head);

	Node* left = head;
	Node* right = mid->next;
	mid->next = NULL;

	//recursive calls to sort both halves
	left = MergeSort(left);
	right = MergeSort(right);

	//merge both left and right halves
	Node* result = Merge(left, right);

	return result;
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

	cout << "Middle Node: " << mylist->MiddleNode()->data << endl;
	mylist->FindNthNodeFromEnd(3);
	mylist->DeleteNthNodeFromEnd(3);
	mylist->Print();

	//mylist->DeleteList();

	delete mylist;

	return 0;
}








