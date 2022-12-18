#include "LinkedList.h"

// Check if a Linked List is a Circular Linked List
bool IsCircularList(Node* head) {
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