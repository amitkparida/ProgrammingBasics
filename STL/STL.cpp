

/*

https://abhiarrathore.medium.com/the-magic-of-c-stl-standard-template-library-e910f43379ea
https://leetcode.com/discuss/study-guide/1327203/C%2B%2B-STL-Guide-or-STL-Operations-and-Time-Complexities
https://leetcode.com/discuss/study-guide/1154632/C%2B%2B-STL-powerful-guide-or-Compiled-list-of-popular-STL-operations
https://leetcode.com/discuss/study-guide/1387739/C%2B%2B-STL-Guide-or-Online-Coding-Rounds-or-Placements-2021-22
https://leetcode.com/discuss/study-guide/1359115/All-C%2B%2B-STL-internal-implementation-oror-last_minute_notes-oror-2021
https://leetcode.com/discuss/study-guide/1068545/HASH-TABLE-and-MAP-POWERFUL-GUIDE


Standard Template Library (STL):
===============================

STL has 4 components

Containers - Containers are used to manage collections of objects of a certain kind.
Algorithms - Algorithms act on containers. They provide the means for various operations such as initialization, sorting, searching, and transforming of the contents of containers.
Iterators - Iterators are used to step through the elements of collections of objects. These collections may be containers or subsets of containers.
Function objects (Functors) - The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. 
Functors allow the working of the associated function to be customized with the help of parameters to be passed.

STL Containers: 
--------------

1. Sequence containers:
Sequence containers implement data structures which can be accessed sequentially.

	array : (C++11) static contiguous array
	vector : dynamic contiguous array
	deque : double-ended queue
	forward_list (C++11) : singly-linked list
	list : doubly-linked list

2. Associative containers:
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

	set : collection of unique keys, sorted by keys
	map : collection of key-value pairs, sorted by keys, keys are unique
	multiset : collection of keys, sorted by keys
	multimap : collection of key-value pairs, sorted by keys

3. Unordered associative containers:
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity).

	unordered_set : collection of unique keys, hashed by keys
	unordered_map : collection of key-value pairs, hashed by keys, keys are unique
	unordered_multiset : collection of keys, hashed by keys
	unordered_multimap : collection of key-value pairs, hashed by keys

4. Container adaptors:
Container adaptors provide a different interface for sequential containers.
	stack
	queue
	priority_queue



Important STL Algorithms:

All of, for_each, max_element, min_element, find, copy, sort, Transform,

*/



/*
set and map are implemented using Red - Black tree.Operations are O(logn).
Elements are sorted.Duplication of keys is not allowed.Multiset and multimap allow duplicate keys.

unordered_set and unordered_map are implemented using Hash Tables.Operations are O(1).Elements are not sorted.

-----------------
Why Red - Black tree is used in set and map, not any other tree ?

Binary search tree operations are also O(logn) in average case, but in worst case if the BST is skewed, the operation will be O(n).

AVL tree is self balancing binary treeand it's operations are O(logn). But the balancing is done more frequently in AVL tree which takes time.

Red - Black tree is like AVL tree, but it does balancing less frequently.

The AVL trees are more balanced compared to Red - Black Trees, but they may cause more rotations during insertionand deletion.
So if your application involves frequent insertions and deletions, then Red - Black trees should be preferred.
And if the insertionsand deletions are less frequentand search is a more frequent operation, then AVL tree should be preferred over the Red - Black Tree.

-----------------

Why set and map are used when unordered set and unordered are more efficient ?

Unordered map or unordered set doesn't allow user defined data types or pairs as keys. only allow integer and string.

map and set allow every data types.Also keys are sorted in map and set.
*/


/*
Vectors
A vector manages its elements in a dynamic array.It enables random access, which means we can access each element directly with index.
Appending and removing elements at the end of the array is very fast.But inserting an element in the middle or at the beginning of the array takes time because all the following elements should be moved to make room for it while maintaining the order.

Deques
Double - ended - queue(deque) is a dynamic array that is implemented so that it can grow in both directions.So, inserting element at the endand at the beginning is fast.Insertingand elements in the middle, however, takes time because element must be moved.

Lists
A list is implemented as a doubly linked list of element.In other words, each element in a list has its own segment of memoryand refers to its predecessorand its successor.Lists do not provide random access.General access to an arbitrary element takes linear timeand this is a lot worse than vectorsand deques.
The advantage of a list is that the insertion or removal of an element is fast at any position.Only the links must be changed.This implies that moving an element in the middle of a list is very fast compared with moving an element in a vector or a deque.
*/