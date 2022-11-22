

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