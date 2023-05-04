
// https://leetcode.com/problems/linked-list-cycle/

#include "LinkedList.h"

// Find if the list contains a Loop or cycle
bool DetectLoop(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return true;
		}
	}

	return false;
}

bool DetectLoop2(Node* head) {
	unordered_map<Node*, bool> visited;

	Node* temp = head;
	while (temp) {
		if (visited[temp] == true) {
			return true;
		}

		visited[temp] = true;
		temp = temp->next;
	}

	return false;
}

bool DetectLoop3(Node* head) {
	unordered_set<Node*> s;

	Node* temp = head;
	while (temp) {
		// if (s.find(temp) != s.end()) {
		if (s.count(temp) > 0) {
			return true;
		}

		s.insert(temp);
		temp = temp->next;
	}

	return false;
}