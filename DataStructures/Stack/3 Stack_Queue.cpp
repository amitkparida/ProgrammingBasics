//Implement Stack using Queue
// https://www.geeksforgeeks.org/implement-stack-using-queue/

#include <iostream>
#include <queue>
using namespace std;

//Implement Stack using 1 Queue
//Time Complexity :
//  Push operation : O(N)
//  Pop operation : O(1)
//Auxiliary Space : O(N) since 1 queue is used.

class Stack {
    queue<int> q;

public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
};

// Push operation
void Stack::push(int data)
{
    //  Get previous size of queue
    int s = q.size();

    // Push the current element
    q.push(data);

    // Pop all the previous elements and put them after current element
    for (int i = 0; i < s; i++) {
        // Add the front element again
        q.push(q.front());

        // Delete front element
        q.pop();
    }
}

// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}

int Stack::top() { 
    return (q.empty()) ? -1 : q.front(); 
}

// Returns true if Stack is empty else false
bool Stack::empty() { 
    return (q.empty()); 
}

int Stack::size() { 
    return q.size(); 
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "current size: " << st.size() << "\n";
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    cout << "current size: " << st.size();
    return 0;
}