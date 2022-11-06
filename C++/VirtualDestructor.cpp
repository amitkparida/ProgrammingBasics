// TOPIC: Virtual Destructor 

// NOTES:
// 1. The base class destructor must be virtual if you delete a derived class object through its base class pointer.
// 2. If we delete derived class object through a pointer of base class then it is undefined behaviour
//    if parent class doesn't have virtual destructor.
// 3. If we fail to declare destructor as virtual in parent class then we end up having memory leak.

#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "ctor Base" << endl; }
    ~Base() { cout << "dtor Base" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "ctor Derived" << endl; }
    ~Derived() { cout << "dtor Derived" << endl; }
};

int main() {
    Derived d;
    cout << sizeof(d) << endl;
    return 0;
}