#include "LinkedList.h"

//Remove the loop in the list
void RemoveLoop(Node* head) {
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
void RemoveLoop2(Node* head) {
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