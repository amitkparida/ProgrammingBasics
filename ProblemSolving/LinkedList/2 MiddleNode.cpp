#include "LinkedList.h"

//Find the middle node using 2 traversals
Node* MiddleNode(Node* head) {
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
Node* MiddleNode2(Node* head) {
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
