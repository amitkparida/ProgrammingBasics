#include "linkedlist.h"

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

