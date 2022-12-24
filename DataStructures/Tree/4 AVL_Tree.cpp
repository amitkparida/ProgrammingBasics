// TOPIC: AVL Tree (Adelson, Velski & Landis)

// Prerequisite is BST;

// NOTES:
// 1. AVL tree is height balancing BST OR self balancing BST.
// 2. Why BST was not enough? and we needed balancing BST (AVL Tree)
//    a. Normal BST is having issue when data is sorted or almost sorted (skewed Binary tree).
//    b. Using AVL tree we keep balancing when it becomes non balanced while inserting data.
// 3. AVL tree take the height of left and right sub tree and find the difference (L-R) and it should be either of {-1,0,1}.
// 4. This difference is called Balance Factor.
// 5. If the balance factor of left and right sub tree is not either of {-1,0,1} then tree is balanced using rotation techniques.
//    A. left left     ==>> Right Rotation 
//    B. left right    ==>> Left and Right Rotation
//    C. right left    ==>> Right and Left Rotation
//    D. right right   ==>> Left 


/*
// PROGRAM from CppNut
#include <iostream> 
using namespace std;

// An AVL tree node  
class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially 
    // added at leaf  
    return(node);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation  
    x->right = y;
    y->left = T2;

    // Update heights  
    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    // Return new root  
    return x;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation  
    y->left = x;
    x->right = T2;

    // Update heights  
    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;

    // Return new root  
    return y;
}

// Get Balance factor of node N  
int getBalance(Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    // 1. Perform the normal BST insertion 
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST  
        return node;

    // 2. Update height of this ancestor node 
    node->height = 1 + max(height(node->left),
        height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced 
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case  
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case  
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case  
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;  // return the (unchanged) node pointer 
}
void preOrder(Node* root) {
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
*/



//From Hemant Jain book

#include <vector>
#include <iostream>

class AVLTree {
private:
    struct Node {
        int data = 0;
        Node* left;
        Node* right;
        int height = 0;

        ~Node();
        Node(int d, Node* l, Node* r);
    };

    Node* root;

public:
    ~AVLTree();
    AVLTree();
    void insert(int data);
    void deleteNode(int data);
    void printTree();
    int max(int a, int b);

private:
    Node* insert(Node* node, int data);
    Node* rightRotate(Node* x); // Function to right rotate subtree rooted with x
    Node* leftRotate(Node* x); // Function to left rotate subtree rooted with x
    Node* rightLeftRotate(Node* x); // Function to right then left rotate subtree rooted with x
    Node* leftRightRotate(Node* x); // Function to left then right rotate subtree rooted with x
    Node* deleteNode(Node* node, int data);
    Node* findMin(Node* curr);
    int height(Node* n);
    int getBalance(Node* node);
    void printTree(Node* node, std::string indent, bool isLeft);
};


AVLTree::Node::Node(int d, Node* l, Node* r) {
	data = d;
	left = l;
	right = r;
	height = 0;
}

AVLTree::Node::~Node() {
	delete left;
	delete right;
}

AVLTree::AVLTree() {
	root = nullptr;
}

AVLTree::~AVLTree() {
	delete root;
}

int AVLTree::height(Node* n) {
	if (n == nullptr) {
		return -1;
	}
	return n->height;
}

int AVLTree::getBalance(Node* node) {
	return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

void AVLTree::insert(int data) {
	root = insert(root, data);
}

AVLTree::Node* AVLTree::insert(Node* node, int data) {
	if (node == nullptr) {
		return new Node(data, nullptr, nullptr);
	}

	if (node->data > data) {
		node->left = insert(node->left, data);
	}
	else if (node->data < data) {
		node->right = insert(node->right, data);
	}
	else { // Duplicate data not allowed
		return node;
	}

	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1) {
		if (data < node->left->data) // Left Left Case
		{
			return rightRotate(node);
		}
		if (data > node->left->data) // Left Right Case
		{
			return leftRightRotate(node);
		}
	}

	if (balance < -1) {
		if (data > node->right->data) // Right Right Case
		{
			return leftRotate(node);
		}
		if (data < node->right->data) // Right Left Case
		{
			return rightLeftRotate(node);
		}
	}
	return node;
}

AVLTree::Node* AVLTree::rightRotate(Node* x) {
	Node* y = x->left;
	Node* T = y->right;

	// Rotation
	y->right = x;
	x->left = T;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

AVLTree::Node* AVLTree::leftRotate(Node* x) {
	Node* y = x->right;
	Node* T = y->left;

	// Rotation
	y->left = x;
	x->right = T;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

AVLTree::Node* AVLTree::rightLeftRotate(Node* x) {
	x->right = rightRotate(x->right);
	return leftRotate(x);
}

AVLTree::Node* AVLTree::leftRightRotate(Node* x) {
	x->left = leftRotate(x->left);
	return rightRotate(x);
}

void AVLTree::deleteNode(int data) {
	root = deleteNode(root, data);
}

AVLTree::Node* AVLTree::deleteNode(Node* node, int data) {
	if (node == nullptr) {
		return nullptr;
	}

	if (node->data == data) {
		if (node->left == nullptr && node->right == nullptr) {
			return nullptr;
		}
		else if (node->left == nullptr) {
			return node->right; // no need to modify height
		}
		else if (node->right == nullptr) {
			return node->left; // no need to modify height
		}
		else {
			Node* minNode = findMin(node->right);
			node->data = minNode->data;
			node->right = deleteNode(node->right, minNode->data);
		}
	}
	else {
		if (node->data > data) {
			node->left = deleteNode(node->left, data);
		}
		else {
			node->right = deleteNode(node->right, data);
		}
	}

	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1) {
		if (data >= node->left->data) // Left Left Case
		{
			return rightRotate(node);
		}
		if (data < node->left->data) // Left Right Case
		{
			return leftRightRotate(node);
		}
	}

	if (balance < -1) {
		if (data <= node->right->data) // Right Right Case
		{
			return leftRotate(node);
		}
		if (data > node->right->data) // Right Left Case
		{
			return rightLeftRotate(node);
		}
	}
	return node;
}

AVLTree::Node* AVLTree::findMin(Node* curr) {
	Node* node = curr;
	if (node == nullptr) {
		return nullptr;
	}

	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

void AVLTree::printTree() {
	std::string str = "";
	printTree(root, str, false);
	std::cout << std::endl;
}

void AVLTree::printTree(Node* node, std::string indent, bool isLeft) {
	if (node == nullptr) {
		return;
	}
	if (isLeft) {
		std::cout << indent << "L:";
		indent += "|  ";
	}
	else {
		std::cout << indent << "R:";
		indent += "   ";
	}

	std::cout << node->data << "(" << node->height << ")" << std::endl;
	printTree(node->left, indent, true);
	printTree(node->right, indent, false);
}

int AVLTree::max(int a, int b) {
	return (a > b) ? a : b;
}

// Testing code.
int main() {
	AVLTree* t = new AVLTree();
	t->insert(1);
	t->insert(2);
	t->insert(3);
	t->insert(4);
	t->insert(5);
	t->insert(6);
	t->insert(7);
	t->insert(8);
	t->printTree();

	t->deleteNode(5);
	t->printTree();

	t->deleteNode(1);
	t->printTree();

	t->deleteNode(2);
	t->printTree();

	delete t;
}

/*
 R:4(3)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:6(2)
	  L:5(0)
	  R:7(1)
		 R:8(0)
R:4(2)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:7(1)
	  L:6(0)
	  R:8(0)
R:4(2)
   L:2(1)
   |  R:3(0)
   R:7(1)
	  L:6(0)
	  R:8(0)
R:4(2)
   L:3(0)
   R:7(1)
	  L:6(0)
	  R:8(0)
 */