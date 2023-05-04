// Add Two Numbers Represented by Linked Lists
// https://leetcode.com/problems/add-two-numbers/
// https://www.youtube.com/watch?v=j36ETLmbr_w&list=PLzjZaW71kMwQ1DIWTn0d_KDHU4_E52-rq&index=31


#include "linkedlist.h"

Node* addTwoNumbers(Node* l1, Node* l2) {
	Node* dummy = new Node(-1);

	Node* temp = dummy;
	int carry = 0;

	while (l1 != NULL || l2 != NULL) {
		int x = l1 ? l1->data : 0;
		int y = l2 ? l2->data : 0;

		int sum = carry + x + y;
		carry = sum / 10;
		
		temp->next = new Node(sum % 10);
		temp = temp->next;

		//l1 = l1 ? l1->next : l1;
		//l2 = l2 ? l2->next : l1;

		if (l1 != NULL) {
			l1 = l1->next;
		}

		if (l2 != NULL) {
			l2 = l2->next;
		}
	}

	if (carry > 0) {
		temp->next = new Node(carry);
	}
	return dummy->next;
}