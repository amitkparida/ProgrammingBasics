
/*

set and map are implemented using Red-Black tree. Operations are O(logn). Elements are sorted. Duplication of keys is not allowed. Multiset and multimap allow duplicate keys.

unordered_set and unordered_map are implemented using Hash Tables. Operations are O(1). Elements are not sorted. 

-------------------
Why Red-Black tree is used in set and map, not any other tree?

Binary search tree operations are also O(logn) in average case, but in worst case if the BST is skewed, the operation will be O(n).
AVL tree is self balancing binary tree and it's operations are O(logn). Red-Black tree's operations are also O(logn). 
The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. 
So if your application involves frequent insertions and deletions, then Red-Black trees should be preferred. 
And if the insertions and deletions are less frequent and search is a more frequent operation, then AVL tree should be preferred over the Red-Black Tree.

------------

Why set and map are used when unordered set and unordered are more efficient?

Unordered map or unordered set doesn't allow user defined data types or pairs as keys. only allow integer and string.

map and set allow every data types. Also keys are sorted in map and set.

*/