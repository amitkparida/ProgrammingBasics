#pragma once

#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

class CLinkedList {
private:
	Node* head;

public:
	CLinkedList();
	~CLinkedList();
	void PushBack(int newdata); //InsertAtTail
	void Print();

	Node* MiddleNode();
	Node* MiddleNode2();
	bool IsCircularList();
	bool DetectLoop();
	bool DetectLoop2();
	bool DetectLoop3();
	Node* DetectStartOfLoop();
	void RemoveLoop();
	void RemoveLoop2();
	Node* RemoveDuplicates();
	Node* RemoveDuplicates1();
	Node* FindNthNodeFromEnd(int n);
	void DeleteNthNodeFromEnd(int n);
	Node* Sort();
	void MakeLoop();
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
}

//InsertAtTail
void CLinkedList::PushBack(int newdata) {
	Node* newnode = NULL, * temp = NULL;

	newnode = new Node(newdata);

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

	//In case of even no of nodes, if you want to consider the 2nd of the 2 middle nodes as Mid.
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	//In case of even no of nodes, if you want to consider the 1st of the 2 middle nodes as Mid.
	//while (fast->next != NULL && fast->next->next != NULL) {
	//	slow = slow->next;
	//	fast = fast->next->next;
	//}

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
	unordered_map<Node*, bool> visited;

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

//Find the starting node of the loop
Node* CLinkedList::DetectStartOfLoop() {
	Node* fast = head;
	Node* slow = head;
	Node* start = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		// If slow == fast, then loop is present.
		if (slow == fast) {
			while (start != slow) {
				//Move both pointers at the same pace, they will meet at loop starting node.
				start = start->next;
				slow = slow->next;
			}

			return start; //Starting node of the loop
		}
	}

	return NULL;
}

//Remove the loop in the list
void CLinkedList::RemoveLoop() {
	Node* fast = head;
	Node* slow = head;
	Node* start = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		// If slow == fast, then loop is present.
		if (slow == fast) {

			// Below check is needed when slow and fast both meet at the head of the list 
			// e.g.: 1->2->3->4->5 and then 5->next = 1 i.e the head of the list.
			if (slow == head) {
				while (slow->next != head) {
					slow = slow->next;
				}
			}
			else {
				// Move the start/head node pointer and the slow pointer to the previous of their meeting point. 
				while (slow->next != start->next) {
					slow = slow->next;
					start = start->next;
				}

			}

			//since slow->next is the loop starting point 
			slow->next = NULL; // remove loop 
			return;
		}
	}

	return;
}

//RemoveLoop using map or set. Extra O(n) space needed.
void CLinkedList::RemoveLoop2() {
	unordered_map<Node*, bool> visited;
	Node* prev = head;
	Node* temp = head;
	while (temp) {
		//if (visited.find(temp) == visited.end()) {
		if (visited[temp] == false) {
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
	// // if (s.find(temp) == s.end()) {
	//	if (s.count(temp) == 0) {	
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
Node* CLinkedList::RemoveDuplicates() {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* curr = head;
	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {

			Node* temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		else {
			curr = curr->next;
		}
	}

	return head;
}

//Anouther approach using extra dummy node
Node* CLinkedList::RemoveDuplicates1() {
	if (head == NULL) {
		return head;
	}

	Node* dummy = new Node;
	dummy->next = head;

	Node* prev = dummy;
	Node* curr = head;
	while (curr != NULL) {
		if (prev->data == curr->data) {

			prev->next = curr->next;
			Node* temp = curr;
			curr = curr->next;
			delete temp;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	delete dummy;
	return head;
}


Node* CLinkedList::FindNthNodeFromEnd(int n)
{
	if (head == NULL || n < 1) {
		return NULL;
	}

	// create two pointers slow and fast initially pointing to head.
	Node* slow = head;
	Node* fast = head;

	// move fast to the n-th node from beginning.
	for (int i = 1; i <= n; i++) {
		if (fast == NULL) {
			cout << n << " is greater than no. of nodes in the list" << endl;
			return NULL;
		}

		fast = fast->next;
	}

	// Move both fast and slow forward until fast reaches end of the list.
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	cout << "Node no. " << n << " from end is: " << slow->data << endl;

	return slow;


	////Alternate approach
	////Create a dummy node before head. 
	//Node* start = new Node;
	//start->next = head;

	//Node* fast = start;
	//Node* slow = start;

	//for (int i = 1; i <= n; i++) {
	//	if (fast == NULL) {
	//		cout << n << " is greater than no. of nodes in the list" << endl;
	//		return NULL;
	//	}

	//	fast = fast->next;
	//}

	//while (fast->next != NULL) {
	//	fast = fast->next;
	//	slow = slow->next;
	//}

	//Node* result = slow->next;

	//cout << "Node no. " << n << " from end is: " << result->data << endl;
	//return result;
}


// Function to delete the nth node from the end.
void CLinkedList::DeleteNthNodeFromEnd(int n)
{
	if (head == NULL || n < 1)
	{
		return;
	}

	//create a dummy node before head. 
	Node* start = new Node;
	start->next = head;

	Node* fast = start;
	Node* slow = start;

	for (int i = 1; i <= n; i++) {
		fast = fast->next;
	}

	while (fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;
	return;
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
	while (temp != NULL) {
		count1++;
		temp = temp->next;
	}

	temp = head2;
	while (temp != NULL) {
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


//Find the intersection point of two linked list. Another approach.
Node* FindIntersection2(Node* headA, Node* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}

	Node* a = headA;
	Node* b = headB;

	while (a != b) {
		//At the end of one list, we just reset the pointer to the head of the other list
		a = (a == NULL) ? headB : a->next;
		b = (b == NULL) ? headA : b->next;

		//if (a == NULL) { 
		//	a = headB;
		//}
		//else {
		//	a = a->next;
		//}

		//if (b == NULL) {
		//	b = headA;
		//}
		//else {
		//	b = b->next;
		//}
	}

	return a;
}


//Find the intersection point of two linked list. Brute Force approach.
Node* FindIntersection3(Node* headA, Node* headB) {
	Node* temp;

	while (headA) {
		temp = headB;

		while (temp) {
			if (temp == headA) {
				return headA;
			}
			temp = temp->next;
		}

		headA = headA->next;
	}
	return NULL;
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

	//temp->next = (list1 != NULL) ? list1 : list2;
	if (list1) temp->next = list1;
	if (list2) temp->next = list2;

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


//Merge sort of Linked List

Node* FindMid(Node* head) {
	Node* fast = head;
	Node* slow = head;

	//In case of even no of nodes, consider the 1st of the 2 middle nodes as Mid.
	while (fast->next != NULL && fast->next->next != NULL) {
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

	// break linked list into 2 halves, after finding mid
	Node* mid = FindMid(head);

	Node* left = head;
	Node* right = mid->next;
	mid->next = NULL;

	//recursive calls to sort both halves
	left = MergeSort(left);
	right = MergeSort(right);

	//merge both left and right halves
	Node* result = MergeTwoLists(left, right);

	return result;
}

Node* CLinkedList::Sort() {
	head = MergeSort(head);
	return head;
}


void CLinkedList::MakeLoop() {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = head;
			return;
		}
		temp = temp->next;
	}
}

