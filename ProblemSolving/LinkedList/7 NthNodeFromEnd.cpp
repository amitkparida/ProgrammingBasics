#include "LinkedList.h"

Node* FindNthNodeFromEnd(Node* head, int n)
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
void DeleteNthNodeFromEnd(Node* head, int n)
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
