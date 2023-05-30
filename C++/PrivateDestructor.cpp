
// Private destructors are quite useful when objects are always required to be allocated on the heap. 
// 
// If destructor is private, 
// - You can only allocate the object on heap. 
// - You cannot delete the object (You will get compilation error). Deletion has to be done via a friend or a member function.
// - You cannot allocate the object on stack. You will get compilation error. 
//   Such an object can be created on the stack only in the scope of a friend or itself. 
//   Such an object can be created on the stack by using placement new.

// if you're doing some sort of reference counting thing, you can have the object (or manager that has been "friend"ed) 
// responsible for counting the number of references to itself and delete it when the number hits zero. 
// A private dtor would prevent anybody else from deleting it when there were still references to it.

// https://stackoverflow.com/questions/631783/what-is-the-use-of-having-destructor-as-private


//COM uses this strategy for deleting the instance.COM makes the destructor private and provides an interface for deleting the instance.
// Here is an example of what a Release method would look like.

/*int MyRefCountedObject::Release()
{
    _refCount--;
    if (0 == _refCount)
    {
        delete this;
        return 0;
    }
    return _refCount;
}*/
// ATL COM objects are a prime example of this pattern.



#include <iostream>
class A {
    ~A() {}
    friend void delete_A(A* p);
};

void delete_A(A* p) {
    delete p;
}

int main()
{
    // A obj; // Compile error C2248: 'A::~A': cannot access private member declared in class 'A'

    A* ptr = new A;

    // delete ptr; //Compile error C2248: 'A::~A': cannot access private member declared in class 'A'

    delete_A(ptr);

    return 0;
}
