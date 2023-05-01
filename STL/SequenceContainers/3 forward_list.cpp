// TOPIC: forward_list In STL

// 1. This is single linked list what we know from C prgramming language.
// 2. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function
// 3. Few Available Operations
//    push_front (push_back is not available), operator =, assign, front, empty, max_size, clear, insert_after, emplace_after,
//    reverse, sort, merge, splice_after, unique, remove, remove_if, resize

#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> list1 = { 5, 6, 7, 8 };

    list1.push_front(4);
    list1.push_front(3);
    list1.push_front(2);

    for (auto& elm : list1)
        cout << elm << endl;
    cout << endl;

    list1.pop_front();

    forward_list<int> list2 = { 7, 6, 1, 9 };
    list1.resize(10); 

    for (auto& elm : list2)
        cout << elm << endl;
    cout << endl;

    return 0;
}