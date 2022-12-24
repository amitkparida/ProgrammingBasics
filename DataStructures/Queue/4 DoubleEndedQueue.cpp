#include<iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size = 100);
    ~Deque();

    bool pushFront(int x);
    bool pushRear(int x);
    int popFront();
    int popRear();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    void display();
};

Deque::Deque(int size)
{
    capacity = size;
    arr = new int[capacity];
    front = -1;
    rear = -1;
}

Deque::~Deque()
{
    delete[] arr;
}

// Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
bool Deque::pushFront(int x)
{
    //check full or not
    if (isFull()) {
        return false;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0 && rear != capacity - 1) {
        front = capacity - 1;
    }
    else
    {
        front--;
    }
    arr[front] = x;
    return true;
}

// Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
bool Deque::pushRear(int x)
{
    if (isFull()) {
        return false;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == capacity - 1 && front != 0) {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = x;
    return true;
}

// Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int Deque::popFront()
{
    if (isEmpty()) {//to check queue is empty
        //cout << "Queue is Empty " << endl;
        return -1;
    }

    int ans = arr[front];
    arr[front] = -1;

    if (front == rear) { //single element is present
        front = rear = -1;
    }
    else if (front == capacity - 1) {
        front = 0; //to maintain cyclic nature
    }
    else
    {//normal flow
        front++;
    }
    return ans;
}

// Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int Deque::popRear()
{
    if (isEmpty()) {//to check queue is empty
        //cout << "Queue is Empty " << endl;
        return -1;
    }

    int ans = arr[rear];
    arr[rear] = -1;

    if (front == rear) { //single element is present
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = capacity - 1; //to maintain cyclic nature
    }
    else
    {//normal flow
        rear--;
    }
    return ans;
}

// Returns the first element of the deque. If the deque is empty, it returns -1.
int Deque::getFront()
{
    if (isEmpty()) {
        return -1;
    }
    return arr[front];
}

// Returns the last element of the deque. If the deque is empty, it returns -1.
int Deque::getRear()
{
    if (isEmpty()) {
        return -1;
    }
    return arr[rear];
}

// Returns true if the deque is empty. Otherwise returns false.
bool Deque::isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

// Returns true if the deque is full. Otherwise returns false.
bool Deque::isFull()
{
    if ((front == 0 && rear == capacity - 1) || (front != 0 && rear == (front - 1) % (capacity - 1))) {
        return true;
    }
    else
    {
        return false;
    }
}

void Deque::display()
{
    int i = front;
    cout << "\nElements in a deque are: ";

    while (i != rear)
    {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << arr[rear] << endl;
}


int main() {
    Deque q(20);
    q.pushFront(20);
    q.pushFront(10);
    q.pushRear(30);
    q.pushRear(50);
    q.pushRear(80);
    q.display();   
    
    cout << "Front : " << q.getFront() << endl;
    cout << "Front : " << q.getRear() << endl;
    q.popFront();
    q.popRear();
    q.display();  

    return 0;
}