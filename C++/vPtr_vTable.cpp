// TOPIC: vptr and vtable 

// vptr NOTES:
// 1. vptr stands for virtual pointer.
// 2. vptr holds the address of vtable.
// 3. vptr is constructed and initialized in constructor.
// 4. vptr is created in every class using virtual functions OR have derived a class which uses virtual functions.
// 5. Every class (as well as object) has its own vptr.
// 6. Different instances of the same class point to same vtable.

// vtable NOTES:
// 1. vtable stands for virtual table.
// 2. vtable is a static table (static array of function pointers) which gets constructed by the compiler at compile time.
// 3. vtable is stored in the data section (.data) of the executable.
// 4. Every class has its own vtable.
// 5. Different instances of the same class point to same vtable.
// 6. vtable store address (with some other info) of virtual functions of own class OR parent class.
// 7. Parent class vtable is copied to child class vtable and then if child class overrides any function then that
//    function address is replaced with child class function.

#include <iostream>
using namespace std;

class Base {
public:
    virtual void fun() { }
};

class Derived : public Base {
public:
    void fun() { }
};

int main() {
    return 0;
}