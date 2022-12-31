// Implementation of Queue using Stack
// https://www.geeksforgeeks.org/queue-using-stacks/

#include <iostream>
#include <stack>
using namespace std;

// Program to implement Queue using two stacks with costly enQueue()
// Time Complexity : 
//   Push operation : O(N). In the worst case we have empty whole of stack 1 into stack 2.
//   Pop operation : O(1). Same as pop operation in stack.
// Auxiliary Space : O(N). Use of stack for storing values.
 
struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};


// Program to implement Queue using two stacks with costly deQueue()

//Time Complexity :
//  Push operation : O(1). Same as pop operation in stack.
//  Pop operation : O(N) in generaland O(1) amortized time complexity.
//  In the worst case we have to empty the whole of stack 1 into stack 2 so its O(N). Amortized time is the way to express the time complexity when an algorithm has the very bad time complexity only once in a while besides the time complexity that happens most of time.So its O(1) amortized time complexity, since we have to empty whole of stack 1 only when stack 2 is empty, rest of the times the pop operation takes O(1) time.
//Auxiliary Space : O(N). Use of stack for storing values.

struct Queue1 {
    stack<int> s1, s2;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};


// Program to implement Queue using one stack and recursive call stack.
//Time Complexity :
//  Push operation : O(1). Same as pop operation in stack.
//  Pop operation : O(N). The difference from above method is that in this method element is returnedand all elements are restored back in a single call.
//Auxiliary Space : O(N). Use of stack for storing values.

struct Queue2 {
    stack<int> s;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = deQueue();

        // push popped item back to the stack
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};


// Driver code
int main()
{
    Queue2 q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}
