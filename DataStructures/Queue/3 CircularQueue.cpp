#include<iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size = 100);
    ~CircularQueue();
    bool enqueue(int data);
    int dequeue();
    void displayQueue();
};


// Initialize your data structure.
CircularQueue::CircularQueue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = rear = -1;
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

// Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
bool CircularQueue::enqueue(int data) {
    if ((front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1))) {
        cout << "Queue is Full\n";
        return false;
    }
    else if (front == -1) //first element to push
    {
        front = rear = 0;

    }
    else if (rear == capacity - 1 && front != 0) {
        rear = 0; //to maintain cyclic nature
    }
    else
    {
        rear++; //normal flow
    }

    arr[rear] = data;

    return true;
}

// Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
int CircularQueue::dequeue() {
    if (front == -1) {//to check queue is empty
        cout << "Queue is Empty\n" << endl;
        return -1;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear) { //single element is present
        front = rear = -1;
    }
    else if (front == capacity - 1) {
        front = 0; //to maintain cyclic nature
    }
    else
    {
        front++; //normal flow
    }

    return data;
}

void CircularQueue::displayQueue()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << endl << "Front -> " << front << endl;

    cout << "Elements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    else
    {
        for (int i = front; i < capacity; i++)
            cout << arr[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }

    cout << endl<< "Rear -> " << rear << endl;
}


int main()
{
    CircularQueue q(5);

    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.dequeue());
    printf("\nDeleted value = %d\n", q.dequeue());

    q.displayQueue();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.displayQueue();

    q.enqueue(20);
    return 0;
}
