#include "LinkedList.hpp"

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
			temp = temp->next;
			list1 = list1->next;
		}
		else {
			temp->next = list2;
			temp = temp->next;
			list2 = list2->next;
		}
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
