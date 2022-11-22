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