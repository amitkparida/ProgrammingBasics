#pragma once

#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};


Node* PushBack(Node*& head, int data); //InsertAtTail
void Print(Node* head);
void DeleteList(Node* head);
void MakeLoop(Node* head);

void Reverse(Node* head);
void Reverse2(Node* head);
void ReverseUsingStack(Node* head);
Node* ReverseUsingRecursion(Node* head);
Node* ReverseUsingRecursion1(Node* head);
void ReverseInBetween(Node* head, int left, int right);
Node* MiddleNode(Node* head);
Node* MiddleNode2(Node* head);
bool DetectLoop(Node* head);
bool DetectLoop2(Node* head);
bool DetectLoop3(Node* head);
Node* DetectStartOfLoop(Node* head);
void RemoveLoop(Node* head);
void RemoveLoop2(Node* head);
bool IsCircularList(Node* head);
Node* FindNthNodeFromEnd(Node* head, int n);
void DeleteNthNodeFromEnd(Node* head, int n);
Node* FindIntersection(Node* head1, Node* head2);
Node* FindIntersection1(Node* headA, Node* headB);
Node* FindIntersection2(Node* headA, Node* headB);
Node* RemoveDuplicates(Node* head);
Node* RemoveDuplicates1(Node* head);
Node* MergeTwoLists(Node* list1, Node* list2);
Node* MergeSort(Node* head);
Node* addTwoNumbers(Node* l1, Node* l2);

