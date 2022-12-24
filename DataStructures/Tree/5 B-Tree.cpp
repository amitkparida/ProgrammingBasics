// TOPIC: B-Tree 

// NOTES:
// 0. B-Tree is a self-balancing search tree (m-way tree, where m is order of tree)
// 1. B-Tree is generalization of BST in which a node can have more than one key and more than one children.
// 2. There are other balancing trees like 
//    a. AVL Tree
//    b. Red-Black Tree
//    But these are for smaller set of data which can reside in main memory (RAM), and B-Tree is used for very big size of data
//    which can't fit in main memory (Example: disk)
// 3. As we all know that disk access time is more then RAM access time, so the whole idea of B-Tree is to reduce 
//    disk access time.
// 4. It maintains sorted data.
// 5. All leafs are always at the same level.
// 6. Creation process is bottom up.
// 7. Like other balanced Binary Search Trees, time complexity to search, insert and delete is O(log n).

// B-TREE PROPERTIES:
// 0. Every node can have max m children.
// 1. Every node has m-1 keys.
// 2. Minimum children for:
//    a. Leaf Node -> 0
//    b. Root Node -> 2
//    c. Internal Nodes -> [m/2]
// 3. Minimum keys:
//    a. Root Node -> 1
//    b. Other Nodes -> [m/2] - 1
// 4. Insertion is always at the leaf node.


// Advantage of B trees:
// 1. Because B trees contain data with each key, frequently accessed nodes can lie closer to the root, and therefore can be accessed more quickly.

// Advantages of B+ trees:
// 1. Because B+ trees don't have data associated with interior nodes, more keys can fit on a page of memory. Therefore, it will require fewer cache misses in order to access data that is on a leaf node.
// 2. The leaf nodes of B+ trees are linked, so doing a full scan of all objects in a tree requires just one linear pass through all the leaf nodes. A B tree, on the other hand, would require a traversal of every level in the tree. This full-tree traversal will likely involve more cache misses than the linear traversal of B+ leaves.

// Indexing:
// https://dzone.com/articles/database-btree-indexing-in-sqlite#:~:text=B%2Btree%20is%20another%20data,is%20a%20sample%20B%2Btree.


#include <vector>
#include <iostream>

class BTree {
private:
	struct Node {
		int n = 0; // Current number of keys
		std::vector<int> keys; // An array of keys
		std::vector<Node*> arr; // An array of child pointers
		bool leaf = false; // Is true when node is leaf. Otherwise false

		// Constructor
		Node(bool leaf, int max);
		~Node();
	};

	Node* root; // Pointer to root node
	int max = 0; // Maximum degree
	int min = 0; // Minimum degree

public:
	~BTree();
	BTree(int dg);
	void printTree();
	void insert(int key);
	void remove(int key);
	bool search(int key);

private:
	void printTree(Node* node, std::string indent);
	void printInOrder(Node* node);
	bool search(Node* node, int key);
	// Insert a new key in this node
	// Arguments are parent, child, index of child and key.
	void insert(Node* parent, Node* child, int index, int key);
	void split(Node* parent, Node* child, int index);
	void remove(Node* node, int key);
	// Returns the index of first key which is greater than or equal to key.
	int findKey(Node* node, int key);
	// Remove the index key from leaf node.
	void removeFromLeaf(Node* node, int index);
	// Remove the index key from a non-leaf node.
	void removeFromNonLeaf(Node* node, int index);
	// To get predecessor of keys[index]
	int getPred(Node* node, int index);
	// To get successor of keys[index]
	int getSucc(Node* node, int index);
	// Make sure that the node have at least min number of keys
	void fixBTree(Node* node, int index);
	// Move a key from parent to right and left to parent.
	void borrowFromLeft(Node* node, int index);
	// Move a key from parent to left and right to parent.
	void borrowFromRight(Node* node, int index);
	// Merge node's children at index and index+1.
	void merge(Node* node, int index);
};


BTree::BTree(int dg) {
	this->root = nullptr;
	this->max = dg; // Max number of children.
	this->min = dg / 2; // Min number of children.
}

BTree::~BTree() {
	delete root;
}

BTree::Node::Node(bool leaf, int max) {
	this->n = 0;
	this->keys = std::vector<int>(max);
	this->arr = std::vector<Node*>(max + 1, nullptr);
	this->leaf = leaf;
}

BTree::Node::~Node() {
	int length = arr.size();
	for (int i = 0; i < length; i++)
		delete arr[i];
}

void BTree::printTree() {
	std::string str = "";
	printTree(root, str);
	std::cout << std::endl;
}

void BTree::printTree(Node* node, std::string indent) {
	if (node == nullptr) {
		return;
	}
	int i;
	for (i = 0; i < node->n; i++) {
		printTree(node->arr[i], indent + "    ");
		std::cout << indent << "key[" << i << "]:" << node->keys[i]
			<< std::endl;
	}
	printTree(node->arr[i], indent + "    ");
}

void BTree::printInOrder(Node* node) {
	int i;
	for (i = 0; i < node->n; i++) {
		if (node->leaf == false) {
			printInOrder(node->arr[i]);
		}
		std::cout << node->keys[i] << " ";
	}

	if (node->leaf == false) {
		printInOrder(node->arr[i]);
	}
}

bool BTree::search(int key) {
	if (root == nullptr) {
		return false;
	}
	return search(root, key);
}

bool BTree::search(Node* node, int key) {
	int i = 0;
	while (i < node->n && node->keys[i] < key) {
		i++;
	}

	// If the found key is equal to key, return this node
	if (node->keys[i] == key) {
		return true;
	}

	// If the key is not found and this is a leaf node
	if (node->leaf == true) {
		return false;
	}

	// Search in the appropriate child
	return search(node->arr[i], key);
}

void BTree::insert(int key) {
	// If tree is empty
	if (root == nullptr) {
		// Allocate memory for root
		root = new Node(true, this->max);
		root->keys[0] = key; // Insert key
		root->n = 1; // Update number of keys in root
		return;
	}

	if (root->leaf == true) {
		// Finds the location where new key can be inserted.
		// By moving all keys greater than key to one place forward.
		int i = root->n - 1;
		while (i >= 0 && root->keys[i] > key) {
			root->keys[i + 1] = root->keys[i];
			i--;
		}

		// Insert the new key at found location
		root->keys[i + 1] = key;
		root->n = root->n + 1;
	}
	else {
		int i = 0;
		while (i < root->n && root->keys[i] < key) {
			i++;
		}
		insert(root, root->arr[i], i, key);
	}
	if (root->n == max) {
		// If root contains more then allowed nodes, then tree grows in height.
		// Allocate memory for new root
		Node* rt = new Node(false, this->max);
		rt->arr[0] = root;
		split(rt, root, 0); // divide the child into two and then add the median to the parent.
		root = rt;
	}
}

void BTree::insert(Node* parent, Node* child, int index, int key) {
	if (child->leaf == true) {
		// Finds the location where new key will be inserted 
		// by moving all keys greater than key to one place forward.
		int i = child->n - 1;
		while (i >= 0 && child->keys[i] > key) {
			child->keys[i + 1] = child->keys[i];
			i--;
		}

		// Insert the new key at found location
		child->keys[i + 1] = key;
		child->n += 1;
	}
	else {
		int i = 0;
		// insert the node to the proper child.
		while (i < child->n && child->keys[i] < key) {
			i++;
		}
		insert(child, child->arr[i], i, key); // parent, child and index of child.
	}

	if (child->n == max) // More nodes than allowed.
	{
		// divide the child into two and then add the median to the parent.
		split(parent, child, index);
	}
}

void BTree::split(Node* parent, Node* child, int index) {
	// Getting index of median.
	int median = max / 2;
	// Reduce the number of keys in child
	child->n = median;

	Node* node = new Node(child->leaf, this->max);
	// Copy the second half keys of child to node
	int j = 0;
	while (median + 1 + j < max) {
		node->keys[j] = child->keys[median + 1 + j];
		j++;
	}
	node->n = j;

	// Copy the second half children of child to node
	j = 0;
	while (child->leaf == false && median + j <= max - 1) {
		node->arr[j] = child->arr[median + 1 + j];
		j++;
	}

	// parent is going to have a new child,
	// create space of new child
	for (j = parent->n; j >= index + 1; j--) {
		parent->arr[j + 1] = parent->arr[j];
	}

	// Link the new child to the parent node
	parent->arr[index + 1] = node;

	// A key of child will move to the parent node. 
	// Find the location of new key by moving
	// all greater keys one space forward.
	for (j = parent->n - 1; j >= index; j--) {
		parent->keys[j + 1] = parent->keys[j];
	}

	// Copy the middle key of child to the parent
	parent->keys[index] = child->keys[median];

	// Increment count of keys in this parent
	parent->n += 1;
}

void BTree::remove(int key) {
	remove(root, key);

	if (root->n == 0) {
		// Shrinking : If root is pointing to empty node.
		// If that node is a leaf node then root will become null.
		// Else root will point to first child of node.
		if (root->leaf) {
			root = nullptr;
		}
		else {
			root = root->arr[0];
		}
	}
}

void BTree::remove(Node* node, int key) {
	int index = findKey(node, key);
	if (node->leaf) {
		if (index < node->n && node->keys[index] == key) {
			removeFromLeaf(node, index); // Leaf node key found.
		}
		else {
			std::cout << "The key " << key << " not found." << std::endl;
			return;
		}
	}
	else {
		if (index < node->n && node->keys[index] == key) {
			removeFromNonLeaf(node, index); // Internal node key found.
		}
		else {
			remove(node->arr[index], key);
		}

		// All the property violation in index subtree only.
		// which include remove from leaf case too.
		if (node->arr[index]->n < min) {
			fixBTree(node, index);
		}
	}
}

int BTree::findKey(Node* node, int key) {
	int index = 0;
	while (index < node->n && node->keys[index] < key) {
		index++;
	}
	return index;
}

void BTree::removeFromLeaf(Node* node, int index) {
	// Move all the keys after the index position one step left.
	for (int i = index + 1; i < node->n; ++i) {
		node->keys[i - 1] = node->keys[i];
	}

	// Reduce the key count.
	node->n--;
	return;
}

void BTree::removeFromNonLeaf(Node* node, int index) {
	int key = node->keys[index];

	// If the child that precedes key has at least min keys,
	// Find the predecessor 'pred' of key in the subtree rooted at index.
	// Replace key by pred and recursively delete pred in arr[index]
	if (node->arr[index]->n > min) {
		int pred = getPred(node, index);
		node->keys[index] = pred;
		remove(node->arr[index], pred);
	}

	// If the child that succeeds key has at least min keys,
	// Find the successor 'succ' of key in the subtree rooted at index+1.
	// Replace key by succ and recursively delete succ in arr[ index+1].
	else if (node->arr[index + 1]->n > min) {
		int succ = getSucc(node, index);
		node->keys[index] = succ;
		remove(node->arr[index + 1], succ);
	}

	// If both left and right subtree has min number of keys.
	// Then merge left, right child along with parent key.
	// Then call remove on the merged child.
	else {
		merge(node, index);
		remove(node->arr[index], key);
	}
	return;
}

int BTree::getPred(Node* node, int index) {
	// Keep moving to the right most node of left subtree until we reach a leaf.
	Node* cur = node->arr[index];
	while (!cur->leaf) {
		cur = cur->arr[cur->n];
	}

	// Return the last key of the leaf
	return cur->keys[cur->n - 1];
}

int BTree::getSucc(Node* node, int index) {
	// Keep moving to the left most node of right subtree until we reach a leaf
	Node* cur = node->arr[index + 1];
	while (!cur->leaf) {
		cur = cur->arr[0];
	}

	// Return the first key of the leaf
	return cur->keys[0];
}

void BTree::fixBTree(Node* node, int index) {
	// If the left sibling has more than min keys.
	if (index != 0 && node->arr[index - 1]->n > min) {
		borrowFromLeft(node, index);
	}
	// If the right sibling has more than min keys.
	else if (index != node->n && node->arr[index + 1]->n > min) {
		borrowFromRight(node, index);
	}
	// If both siblings has less than min keys.
	// When right sibling exist always merge with the right sibling.
	// When right sibling does not exist then merge with left sibling.
	else {
		if (index != node->n) {
			merge(node, index);
		}
		else {
			merge(node, index - 1);
		}
	}
}

void BTree::borrowFromLeft(Node* node, int index) {
	Node* child = node->arr[index];
	Node* sibling = node->arr[index - 1];

	// Moving all key in child one step forward.
	for (int i = child->n - 1; i >= 0; i--) {
		child->keys[i + 1] = child->keys[i];
	}

	// Move all its child pointers one step forward.
	for (int i = child->n; !child->leaf && i >= 0; i--) {
		child->arr[i + 1] = child->arr[i];
	}

	// Setting child's first key equal to of the current node.
	child->keys[0] = node->keys[index - 1];

	// Moving sibling's last child as child's first child.
	if (!child->leaf) {
		child->arr[0] = sibling->arr[sibling->n];
	}

	// Moving the key from the sibling to the parent
	node->keys[index - 1] = sibling->keys[sibling->n - 1];

	// Increase child key count and decrease sibling key count.
	child->n += 1;
	sibling->n -= 1;
	return;
}

void BTree::borrowFromRight(Node* node, int index) {
	Node* child = node->arr[index];
	Node* sibling = node->arr[index + 1];

	// node key is inserted as the last key in child.
	child->keys[child->n] = node->keys[index];

	// Sibling's first child is inserted as the last child of child.
	if (!(child->leaf)) {
		child->arr[(child->n) + 1] = sibling->arr[0];
	}

	//First key from sibling is inserted into node.
	node->keys[index] = sibling->keys[0];

	// Moving all keys in sibling one step left
	for (int i = 1; i < sibling->n; ++i) {
		sibling->keys[i - 1] = sibling->keys[i];
	}

	// Moving the child pointers one step behind
	for (int i = 1; !sibling->leaf && i <= sibling->n; ++i) {
		sibling->arr[i - 1] = sibling->arr[i];
	}

	// Increase child key count and decrease sibling key count.
	child->n += 1;
	sibling->n -= 1;
	return;
}

void BTree::merge(Node* node, int index) {
	Node* left = node->arr[index];
	Node* right = node->arr[index + 1];
	int start = left->n;
	// Adding a key from node to the left child.
	left->keys[start] = node->keys[index];

	// Copying the keys from right to left.
	for (int i = 0; i < right->n; ++i) {
		left->keys[start + 1 + i] = right->keys[i];
	}

	// Copying the child pointers from right to left.
	for (int i = 0; !left->leaf && i <= right->n; ++i) {
		left->arr[start + 1 + i] = right->arr[i];
	}

	// Moving all keys after  index in the current node one step forward.
	for (int i = index + 1; i < node->n; ++i) {
		node->keys[i - 1] = node->keys[i];
	}

	// Moving the child pointers after (index+1) in the current node one step forward.
	for (int i = index + 2; i <= node->n; ++i) {
		node->arr[i - 1] = node->arr[i];
	}

	// Updating the key count of child and the current node
	left->n += right->n + 1;
	node->n--;
	return;
}

// Testing code.
int main() {
	BTree t(3); // A B-Tree with max key 3
	t.insert(1);
	t.insert(2);
	t.insert(3);
	t.insert(4);
	t.insert(5);
	t.insert(6);
	t.insert(7);
	t.insert(8);
	t.insert(9);
	t.insert(10);
	t.printTree();

	std::cout << "6 found: " << t.search(6) << std::endl;
	std::cout << "11 found: " << t.search(11) << std::endl;

	t.remove(6);
	t.remove(3);
	t.remove(7);
	t.printTree();
}

/*
key[0]:1
key[0] : 2
key[0] : 3
key[0] : 4
key[0] : 5
key[0] : 6
key[0] : 7
key[1] : 8
key[0] : 9
key[1] : 10

6 found : 1
11 found : 0
key[0] : 1
key[1] : 2
key[0] : 4
key[0] : 5
key[1] : 8
key[0] : 9
key[1] : 10
*/