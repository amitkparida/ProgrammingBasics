// TOPIC: Binary Search Tree (BST)

// NOTES:
// 0. In BST, a node at max can have two childrens (Left, Right)
// 1. Binary Search Tree is a binary tree data structure which has the following properties.
//    a. The left subtree of a node 'A' should contain all the nodes with lesser value than 'A'.
//    b. The right subtree of a node 'A' should contain all the nodes with higher value than 'A'.
//    c. The left and right subtree also must be a binary search tree.
// 2. It is like having sorted data in tree.
// 3. In-order to have sorted data in tree, tree should have above three properties.

// BENEFITS:
// 0. Instead of using sorted array if we use BST then complexity of Insert, Delete becomes logN.
// 1. As it maintains sorted elements you have all advantages of data being sorted.

// COMPLEXITY:
// 1. Search, Insert, Delete Complexity: O(logN)
// 2. Space Complexity: O(n)


#include <iostream>
using namespace std;

struct Node {
public:
	int data;
	Node* left;
	Node* right;
	Node() : data(0), left(NULL), right(NULL) {}
	Node(int x) : data(x), left(NULL), right(NULL) {}
	Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

Node* insert(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	}

	//recursion case 
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}

	return root;
}

//O(H)
bool search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	if (root->data == data) {
		return true;
	}

	if (data < root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

void printInOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

Node* findMin(Node* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* findMax(Node* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

//BST Deletion
Node* remove(Node* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	else if (key < root->data) {
		root->left = remove(root->left, key);
	}
	else if (key > root->data) {
		root->right = remove(root->right, key);
	}
	else {
		//when the current node matches with the key
		
		// No children 
		if (root->left == NULL and root->right == NULL) {
			delete root;
			root = NULL;
		}
		// Single Child
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		//2 Children
		else {
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(root->right, temp->data);
		}

	}
	return root;

}

bool isBSTUtil(Node* root, int min, int max) {
	if (root == NULL) {
		return true;
	}

	if (root->data < min || root->data > max) {
		return false;
	}

	return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
	return (isBSTUtil(root, INT_MIN, INT_MAX));
}


//Another approach
bool isBST2(Node* root) {
	if (root == NULL) {
		return true;
	}

	if ((root->left != NULL && findMax(root->left)->data > root->data) ||
	    (root->right != NULL && findMin(root->right)->data <= root->data))
	{
		return false;
	}
	return (isBST2(root->left) && isBST2(root->left));
}


//Challenge : Print all elements of BST which lie in the range k1 and k2
void printRange(Node* root, int k1, int k2) {
	if (root == NULL) {
		return;
	}

	if (root->data >= k1 and root->data <= k2) {
		//call on both sides
		printRange(root->left, k1, k2);
		cout << root->data << " ";
		printRange(root->right, k1, k2);
	}
	else if (root->data > k2) {
		printRange(root->left, k1, k2);
	}
	else {
		// root->data < k1
		printRange(root->right, k1, k2);
	}
}


int main() {

	Node* root = NULL;
	int arr[] = { 8,3,10,1,6,14,4,7,13 };

	for (int x : arr) {
		root = insert(root, x);
	}
	printInOrder(root);
	cout << endl;

	//int key;
	//cin>>key;
	//root = remove(root,key);
	//cout<<search(root,key) <<endl;
	//printInOrder(root);
	cout << "Range is: " << endl;
	printRange(root, 5, 12);



	return 0;
}
