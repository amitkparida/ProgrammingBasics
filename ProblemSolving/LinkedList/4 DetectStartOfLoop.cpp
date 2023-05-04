
// https://leetcode.com/problems/linked-list-cycle-ii/

#include "linkedlist.h"

//Find the starting node of the loop
Node* DetectStartOfLoop(Node* head) {
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