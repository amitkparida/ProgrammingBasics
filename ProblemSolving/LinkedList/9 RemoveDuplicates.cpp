#include "LinkedList.h"

//Remove duplicates from a sorted list.
Node* RemoveDuplicates(Node* head) {
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
Node* RemoveDuplicates1(Node* head) {
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
