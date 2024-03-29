// TOPIC: Cicular Linked List

// NOTES:
// 1. Circular linked list is modified version of singly linked list.
// 2. In circular linked list last node point to first node.

// INSERTIONS:
// 1. Insertion in an empty list
// 2. Insertion at the beginning of the list
// 3. Insertion at the end of the list
// 4. Insertion in between the nodes

// ADVANTAGES:
// 1. CPU sheduling
// 2. Queue can be implemented using one pointer (last). Becuase next to last is always first
//    so we don't have to implement first pointer at all.
// 3. Applications where you don't want to reset once you reach to last node.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(this) {}
    Node(int x) : data(x), next(this) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList();
    ~CircularLinkedList();

    Node* addToEmpty(int data);
    Node* addHead(int data);
    Node* addTail(int data);
    Node* addAfter(int data, int key);
    void deleteNode(int key);
    void deteteList();
    void print();
};

CircularLinkedList::CircularLinkedList() {
    tail = NULL;
}

CircularLinkedList::~CircularLinkedList() {
    if (tail != NULL) {
        Node* head = tail->next;
        Node* temp;
        while (head != tail) {
            temp = head;
            head = head->next;
            delete temp;
        }
        delete tail;
        tail = NULL;
    }
}

Node* CircularLinkedList::addToEmpty(int data) {
    if (tail != NULL) {
        return tail;
    }

    Node* newnode = new Node(data);
    tail = newnode;
    tail->next = tail; //Not needed as it's handled in Node(int x) constructor.

    return tail;
}

// add node to the start
Node* CircularLinkedList::addHead(int data) {
    Node* newnode = new Node(data);

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode; //Make newnode as Head
    }

    return tail;
}

// add node to the end
Node* CircularLinkedList::addTail(int data) {
    Node* newnode = new Node(data);

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode; //Make newnode as Tail
    }

    return tail;
}

// insert node after a specific node
Node* CircularLinkedList::addAfter(int data, int key) {
    if (tail == NULL) {
        return NULL;
    }

    Node* newnode, * temp;

    temp = tail->next;

    do {
        // if the key is found, place newNode after it
        if (temp->data == key) {
            newnode = new Node(data);
            newnode->next = temp->next;
            temp->next = newnode;

            if (temp == tail) {
                tail = newnode;
            }
            return tail;
        }

        temp = temp->next;

    } while (temp != tail->next);

    cout << "\nThe given node is not present in the list" << endl;
    return tail;
}

// delete a node. Note that Node* is passed as a reference.
void CircularLinkedList::deleteNode(int key) {
    if (tail == NULL) {
        return;
    }

    // if the list contains only a single node
    if (tail->data == key && tail->next == tail) {
        delete tail;
        tail = NULL;
        return;
    }

    Node* temp = tail, * d;

    // if last is to be deleted
    if (tail->data == key) {
        // find the node before the last node
        while (temp->next != tail) {
            temp = temp->next;
        }

        // point temp node to the next of last i.e. first node
        temp->next = tail->next;
        delete tail;
        tail = temp->next;
    }

    // travel to the node to be deleted
    while (temp->next != tail && temp->next->data != key) {
        temp = temp->next;
    }

    // if node to be deleted was found
    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        delete d;
    }
}

void CircularLinkedList::deteteList() {
    if (tail == NULL) {
        return;
    }

    Node* head = tail->next;
    Node* temp;
    while (head != tail) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete tail;
    tail = NULL;

    //Node* temp = tail->next;
    //Node* next;
    //while (temp != tail) {
    //    next = temp->next;
    //    delete temp;
    //    temp = next;
    //}
    //delete tail;
    //tail = NULL;
}

void CircularLinkedList::print() {
    if (tail == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Node* temp = tail->next; //head
    do {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != tail->next);

    //Node* temp = tail->next;
    //while (temp != tail) {
    //    cout << temp->data << " ";
    //    temp = temp->next;
    //}
    // 
    //cout << temp->data << endl;
}


int main() {
    CircularLinkedList ll;
    ll.addToEmpty(6);
    ll.addTail(8);
    ll.addHead(2);
    ll.addAfter(10, 2);
    ll.addAfter(9, 8);
    ll.print();
    cout << endl;

    ll.deleteNode(8);
    ll.print();

    return 0;
}