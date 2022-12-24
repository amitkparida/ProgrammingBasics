//What is Red Black Tree ?
//1. It is self balancing binary search tree(BST)

//Why Red Black Tree ?
//1. They are self balancing Binary Search Tree.
//2. RB trees are good at frequent insertion and deletion than lookup(search).
//3. It has less rotations than AVL tree.
//4. It has less memory footprint than AVL tree.
//5. Red Black Trees are used in most of the language libraries like map, multimap, multiset in C++ whereas AVL trees are used in databases where faster retrievals are required.

//RB Tree General Rules :
//1. Nodes are either Red OR Black.
//2. Root is always black.
//3. Every path from the root to any of the leaf nodes must have the same number of black nodes.
//4. No two red nodes can be adjacent, i.e., a red node cannot be the parent or the child of another red node.
//5. All null nodes are considered Black nodes.

//RB Insertion Rules :
//1. If tree is empty then create a Black root node.
//2. Insert new leaf node as Red.
//	1) If Parent is Black then no problem we are good.
//	2) If Parent is Red
//		a) If Black or absent sibling then rotate then re - color and done.
//		b) If Red sibling then re - color and check again.



#include <iostream>
#include <vector>

class RBTree {
private:
	struct Node {
		Node* left, * right, * parent, * nullNode;
		int data = 0;
		bool colour = false; // true for red colour, false for black colour
		~Node();
		Node(int data, Node* nullNode);
	};

	Node* root;
	Node* nullNode;

public:
	~RBTree();
	RBTree();
	void printTree();
	void insert(int data);
	void remove(int data);

private:
	bool isRed(Node* node); // To check whether node is of colour red or not.
	Node* getUncle(Node* node);
	Node* rightRotate(Node* x); // Function to right rotate subtree rooted with x
	Node* leftRotate(Node* x); // Function to left rotate subtree rooted with x
	Node* rightLeftRotate(Node* node);
	Node* leftRightRotate(Node* node);
	Node* find(int data);
	void printTree(Node* node, std::string indent, bool isLeft);
	Node* insert(Node* node, int data);
	void fixRedRed(Node* x);
	void remove(Node* node, int key);
	void fixDoubleBlack(Node* x);
	Node* getSibling(Node* node);
	void joinParentChild(Node* u, Node* v);
	Node* minimum(Node* node);
};


RBTree::Node::Node(int data, Node* nullNode) {
	this->data = data;
	this->left = nullNode;
	this->right = nullNode;
	this->colour = true; // New node are red in colour.
	this->parent = nullNode;
	this->nullNode = nullNode; // used only in delete to prevent double delete.
}

RBTree::Node::~Node() {
	if (left != nullNode)
		delete left;
	if (right != nullNode)
		delete right;
}

RBTree::RBTree() {
	nullNode = new Node(0, nullptr);
	nullNode->colour = false;
	root = nullNode;
}

RBTree::~RBTree() {
	delete root;
	delete nullNode;
}

bool RBTree::isRed(Node* node) {
	return (node == nullptr) ? false : (node->colour == true);
}

void RBTree::printTree() {
	printTree(root, "", false);
	std::cout << std::endl;
}

void RBTree::printTree(Node* node, std::string indent, bool isLeft) {
	if (node == nullNode) {
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

	std::cout << node->data << "(" << node->colour << ")" << std::endl;
	printTree(node->left, indent, true);
	printTree(node->right, indent, false);
}


RBTree::Node* RBTree::getUncle(Node* node) {
	// If no parent or grandparent, then no uncle
	if (node->parent == nullNode || node->parent->parent == nullNode) {
		return nullptr;
	}

	if (node->parent == node->parent->parent->left) // uncle on right
	{
		return node->parent->parent->right;
	}
	else // uncle on left
	{

		return node->parent->parent->left;
	}
}

RBTree::Node* RBTree::rightRotate(Node* x) {
	Node* y = x->left;
	Node* T = y->right;

	// Rotation
	y->parent = x->parent;
	y->right = x;
	x->parent = y;
	x->left = T;

	if (T != nullNode) {
		T->parent = x;
	}

	if (x == root) {
		root = y;
		return y;
	}

	if (y->parent->left == x) {
		y->parent->left = y;
	}
	else {
		y->parent->right = y;
	}

	return y; // Return new root
}

RBTree::Node* RBTree::leftRotate(Node* x) {
	Node* y = x->right;
	Node* T = y->left;

	// Rotation
	y->parent = x->parent;
	y->left = x;
	x->parent = y;
	x->right = T;

	if (T != nullNode) {
		T->parent = x;
	}

	if (x == root) {
		root = y;
		return y;
	}

	if (y->parent->left == x) {
		y->parent->left = y;
	}
	else {
		y->parent->right = y;
	}

	return y; // Return new root
}

RBTree::Node* RBTree::rightLeftRotate(Node* node) {
	node->right = rightRotate(node->right);
	return leftRotate(node);
}

RBTree::Node* RBTree::leftRightRotate(Node* node) {
	node->left = leftRotate(node->left);
	return rightRotate(node);
}

RBTree::Node* RBTree::find(int data) {
	Node* curr = root;
	while (curr != nullNode) {
		if (curr->data == data) {
			return curr;
		}
		else if (curr->data > data) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return nullptr;
}

void RBTree::insert(int data) {
	root = insert(root, data);
	Node* temp = find(data);
	fixRedRed(temp);
}

RBTree::Node* RBTree::insert(Node* node, int data) {
	if (node == nullNode) {
		node = new Node(data, nullNode);
	}
	else if (node->data > data) {
		node->left = insert(node->left, data);
		node->left->parent = node;
	}
	else if (node->data < data) {
		node->right = insert(node->right, data);
		node->right->parent = node;
	}
	return node;
}

void RBTree::fixRedRed(Node* x) {
	// if x is root colour it black and return
	if (x == root) {
		x->colour = false;
		return;
	}

	if (x->parent == nullNode || x->parent->parent == nullNode) {
		return;
	}
	// Initialize parent, grandparent, uncle
	Node* parent = x->parent, * grandparent = parent->parent, * uncle = getUncle(
		x);
	Node* mid = nullptr;

	if (parent->colour == false) {
		return;
	}

	// parent colour is red. gp is black.
	if (uncle != nullNode && uncle->colour == true) {
		// uncle and parent is red.
		parent->colour = false;
		uncle->colour = false;
		grandparent->colour = true;
		fixRedRed(grandparent);
		return;
	}

	// parent is red, uncle is black and gp is black.
	// Perform LR, LL, RL, RR
	if (parent == grandparent->left && x == parent->left) // LL
	{
		mid = rightRotate(grandparent);
	}
	else if (parent == grandparent->left && x == parent->right) // LR
	{
		mid = leftRightRotate(grandparent);
	}
	else if (parent == grandparent->right && x == parent->left) // RL
	{
		mid = rightLeftRotate(grandparent);
	}
	else if (parent == grandparent->right && x == parent->right) // RR
	{
		mid = leftRotate(grandparent);
	}

	mid->colour = false;
	mid->left->colour = true;
	mid->right->colour = true;
}

void RBTree::remove(int data) {
	remove(this->root, data);
}

void RBTree::remove(Node* node, int key) {
	Node* z = nullNode;
	Node* x, * y;
	while (node != nullNode) {
		if (node->data == key) {
			z = node;
			break;
		}
		else if (node->data <= key) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}

	if (z == nullNode) {
		std::cout << "Couldn't find key in the tree" << std::endl;
		return;
	}

	y = z;
	bool yColour = y->colour;
	if (z->left == nullNode) {
		x = z->right;
		joinParentChild(z, z->right);
	}
	else if (z->right == nullNode) {
		x = z->left;
		joinParentChild(z, z->left);
	}
	else {
		y = minimum(z->right);
		yColour = y->colour;
		z->data = y->data;
		joinParentChild(y, y->right);
		x = y->right;
	}

	if (yColour == false) {
		if (x->colour == true) {
			x->colour = false;
			return;
		}
		else {
			fixDoubleBlack(x);
		}
	}
}

void RBTree::fixDoubleBlack(Node* x) {
	if (x == root) // Root node.
	{
		return;
	}

	Node* sib = getSibling(x);
	Node* parent = x->parent;
	if (sib == nullNode) {
		// No sibling double black shifted to parent.
		fixDoubleBlack(parent);
	}
	else {
		if (sib->colour == true) {
			// Sibling colour is red.
			parent->colour = true;
			sib->colour = false;
			if (sib->parent->left == sib) {
				// Sibling is left child.
				rightRotate(parent);
			}
			else {
				// Sibling is right child.
				leftRotate(parent);
			}
			fixDoubleBlack(x);
		}
		else {
			// Sibling colour is black
			// At least one child is red.
			if (sib->left->colour == true || sib->right->colour == true) {
				if (sib->parent->left == sib) {
					// Sibling is left child.
					if (sib->left != nullNode && sib->left->colour == true) {
						// left left case.
						sib->left->colour = sib->colour;
						sib->colour = parent->colour;
						rightRotate(parent);
					}
					else {
						// left right case.
						sib->right->colour = parent->colour;
						leftRotate(sib);
						rightRotate(parent);
					}
				}
				else {
					// Sibling is right child.
					if (sib->left != nullNode && sib->left->colour == true) {
						// right left case.
						sib->left->colour = parent->colour;
						rightRotate(sib);
						leftRotate(parent);
					}
					else {
						// right right case.
						sib->right->colour = sib->colour;
						sib->colour = parent->colour;
						leftRotate(parent);
					}
				}
				parent->colour = false;
			}
			else {
				// Both children black.
				sib->colour = true;
				if (parent->colour == false) {
					fixDoubleBlack(parent);
				}
				else {
					parent->colour = false;
				}
			}
		}
	}
}

RBTree::Node* RBTree::getSibling(Node* node) {
	// sibling null if no parent
	if (node->parent == nullNode) {
		return nullptr;
	}

	if (node->parent->left == node) {
		return node->parent->right;
	}

	return node->parent->left;
}

void RBTree::joinParentChild(Node* u, Node* v) {
	if (u->parent == nullNode) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

RBTree::Node* RBTree::minimum(Node* node) {
	while (node->left != nullNode) {
		node = node->left;
	}
	return node;
}

// Testing code.
int main() {
	RBTree* tree = new RBTree();
	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(7);
	tree->insert(6);
	tree->insert(8);
	tree->insert(9);
	tree->printTree();
	tree->remove(4);
	tree->printTree();
	delete tree;
}

/*
R:4(0)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:6(1)
	  L:5(0)
	  R:8(0)
		 L:7(1)
		 R:9(1)
R:5(0)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:7(1)
	  L:6(0)
	  R:8(0)
		 R:9(1)
*/