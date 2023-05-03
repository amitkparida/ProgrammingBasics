// TOPIC: Unique Pointer In C++

// NOTES:
// 0. unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer, when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use -> and * on the object of unique_ptr, because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.
// 6. Ownership cannot be shared, i.e. copies are not allowed. 

// OPERATIONS:
// release, reset, swap, get, get_deleter.

// https://www.udemy.com/course/beg-modern-cpp/learn/lecture/27006062#overview
// unique_ptr : https://www.youtube.com/watch?v=DHu0tv2qTYo&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=35
// Custom Deleters : https://www.youtube.com/watch?v=BY7wtCiy1uY&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=84

// PROGRAM: 

#include<iostream>
#include<memory>
using namespace std;

class Foo {
    int x;
public:
    explicit Foo(int x) : x{ x }{}
    int getX() { return x; }
    ~Foo() { cout << "Foo Destructor" << endl; }
};

int main() {
    // Foo *f = new Foo(10);
    // cout << f->getX() << endl;

    // std::unique_ptr<Foo> p(new Foo(10));
    // cout << p->getX() << endl;

    std::unique_ptr<Foo> p1(new Foo(10));
    std::unique_ptr<Foo> p2 = make_unique<Foo>(20);//Another way of declaration. make_unique is exception safe
    //auto p2 = make_unique<Foo>(20);
    // std::unique_ptr<Foo> p2 = std::unique_ptr<Foo>(new Foo(20));

    std::cout << p1->getX() << endl << (*p2).getX() << endl;

    //unique_ptr<Foo> p3 = p1; //FAIL: This will fail because you can not copy ownership
    unique_ptr<Foo> p3 = std::move(p1); //SUCCESS: Because moving ownership is allowed. After move, p1's pointer member will be NULL.

    Foo* pObj = p3.get();
    Foo* pObj2 = p3.release(); //p3's pointer member will be copied to pObj2 and then becomes NULL

    p2.reset(pObj2);

    cout << p2->getX() << endl;

    return 0;
}