// TOPIC: list In STL

// 1. This is double linked list what we know from C prgramming language.
// 2. List is sequence container that allow non-contiguous memory allocation.
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of 
//    insertion, removal and moving elements in any position provided we have the iterator of the position. 
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. Few Available Operations
//    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
//    pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.

#include <iostream>
#include <list>
using namespace std;

void displayList(list<int> l) {
    for (auto elm : l)
        cout << elm << ' ';
    cout << endl;
}

int main() {
    list<int> list1 = { 7, 6, 1, 9 };
    list1.push_back(3);
    list1.push_back(2);
    list1.push_front(1);

    for (auto elm : list1)
        cout << elm << ' ';
    cout << endl;

    cout << "front element of list list1 is " << list1.front() << endl;
    cout << "back element of list list1 is " << list1.back() << endl;

    list<int> list2 = { 5, 2, 4, 6, 2, 2, 2 };

    list2.sort(); // sort the linked list
    displayList(list2);

    list2.reverse(); // reverse the linked list
    displayList(list2);

    list2.unique();
    displayList(list2);

    list2.pop_back(); // remove an element from back of list
    displayList(list2);

    list2.pop_front(); // remove an element from front of list
    displayList(list2);

    return 0;
}