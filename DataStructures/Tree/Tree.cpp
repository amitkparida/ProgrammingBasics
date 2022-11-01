// TOPIC: Tree Data Structure Introduction

// NOTES:
// 0. Tree is a hierarchical data structure which stores the information in the form of hierarchy.
// 1. Tree is a non-linear data structure compared to arrays, linked lists, stack and queue.
// 2. Tree represents the nodes connected by edges.
// 3. Tree is one of the most powerful and advanced data structures.

// TREE TERMINOLOGIES:
// Root, Parent Node, Child Node, Siblings, Path, Height of Node, Height of Tree, Depth of Node, Degree of Node, Edge.


// TYPES OF TREE WE WILL COVER IN THIS SERIES:
// Binary Tree, Binary Search Tree, AVL Tree, Red-Black Tree, Splay Tree, N-ary Tree, Tri Structure, 
// Suffix Tree, Huffman Tree, Heap Structure, B Tree, B+ Tree, R Tree, Counted-B Tree, K-D Tree,
// Decision Tree, Markel Tree, Fenwick Tree, Range Tree


// ADVANTAGES OF TREE DATA STRUCTURE:
// 0. Tree reflects structural relationships in the data.
// 1. It is used to represent hierarchies.
// 2. It provides an efficient insertion and searching operations.
// 3. Trees are flexible. It allows to move subtrees around with minimum effort.


// Tree Traversal:
// 1. Breadth First Traversal
// 2. Depth First Traversal
		
// Breadth First Traversal:
// 0. Also called Level Order Traversal
// 1. It uses queue

// Depth First Traversal:
// 0. There are three types of DFT on binary tree.
// 	  a. Pre Order Traversal
//    b. In Order Traversal
//    c. Post Order Traversal
// 1. DFT uses stack (recursion)


// EASY WAY TO REMEMBER
// PRE ORDER
//      cout << root->data << endl;
//      dfs(root->left);
//      dfs(root->right);

// IN ORDER
//      dfs(root->left);
//      cout << root->data << endl;
//      dfs(root->right);

// POST ORDER
//      dfs(root->left);
//      dfs(root->right);
//      cout << root->data << endl;