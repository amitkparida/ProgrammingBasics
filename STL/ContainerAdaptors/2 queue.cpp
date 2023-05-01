// TOPIC: std::queue In C++

// NOTES:
// 0. std::queue class is a container adapter that gives the programmer the functionality of a queue
// 1. queue is FIFO (first-in, first-out) data structure.
// 2. std::queue provides only specific set of functions.
// 3. std::queue allows to push(insert) at back and pop(remove) from front.
// 4. std::queue gives front, back, push, pop, empty, size.

// PROGRAM:
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // get the size of queue
    cout << "The size of queue is " << q.size() << endl;

    // iterate till queue is not empty
    while (!q.empty()) {
        cout << q.front() << " "; // get the front element of queue
        q.pop(); // remove the front element of queue
    }
}

// 1 2 3 4