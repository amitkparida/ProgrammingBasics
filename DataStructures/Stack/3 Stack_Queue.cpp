//Implement Stack using Queue

#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int>* que1 = new std::queue<int>();
    queue<int>* que2 = new std::queue<int>();
    int size = 0;

public:
    virtual void push(int value);
    virtual int pop();
    virtual int pop2();
};


void Stack::push(int value) {
    que1->push(value);
    size += 1;
}

int Stack::pop() {
    int value = 0, s = size;
    while (s > 0) {
        value = que1->front();
        que1->pop();
        if (s > 1)
            que2->push(value);
        s--;
    }
    queue<int>* temp = que1;
    que1 = que2;
    que2 = temp;
    size -= 1;
    return value;
}

int Stack::pop2() {
    int value = 0, s = size;
    while (s > 0) {
        value = que1->front();
        que1->pop();
        if (s > 1)
            que1->push(value);
        s--;
    }
    size -= 1;
    return value;
}

// Testing code.
int main() {
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << "Stack pop : " << stk.pop2() << endl;
    cout << "Stack pop : " << stk.pop2() << endl;
    return 0;
}