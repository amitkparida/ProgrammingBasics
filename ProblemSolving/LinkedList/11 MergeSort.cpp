#include "linkedlist.hpp"

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

Node* Merge(Node* list1, Node* list2) {
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
	Node* result = Merge(left, right);

	return result;
}
