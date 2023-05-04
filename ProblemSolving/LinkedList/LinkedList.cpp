
#include "LinkedList.h"

int main() 
{
	Node* head = NULL;
	 
	//PushBack(head, 1);
	//PushBack(head, 2);
	//PushBack(head, 3);
	//PushBack(head, 4);
	//PushBack(head, 5);
	//PushBack(head, 6);

	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);

	Print(head);

	//mylist->DeleteNode(200);

	cout << "Middle Node: " << MiddleNode(head)->data << endl;
	FindNthNodeFromEnd(head, 1);
	DeleteNthNodeFromEnd(head, 1);
	Print(head);

	cout << "Sort the list: " << endl;
	MergeSort(head);
	Print(head);
	Print(ReverseUsingRecursion1(head));

	DeleteList(head);


	cout << "Add Two Numbers: " << endl;

	Node* list1 = new Node(2);
	list1->next = new Node(4);
	list1->next->next = new Node(3);

	Node* list2 = new Node(5);
	list2->next = new Node(6);
	list2->next->next = new Node(4);

	Print(addTwoNumbers(list1, list2));


	return 0;
}


//InsertAtTail
Node* PushBack(Node*& head, int data) {
	Node* newnode = NULL, * temp = NULL;

	newnode = new Node(data);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
	}

	return head;
}

void Print(Node* head) {
	Node* temp = head;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;

		if (temp != NULL) {
			cout << " -> ";
		}
	}
	cout << endl;
}

void DeleteList(Node* head) {
	Node* temp = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void MakeLoop(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = head;
			return;
		}
		temp = temp->next;
	}
}

