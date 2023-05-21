// TOPIC: Shared Pointer In C++

// NOTES:
// 0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
// 1. Several shared_ptr can point to the same object (managed object).
// 2. It keeps a reference count (maintained in control block) to maintain how many shared_ptr are pointing to the same object.
//    and once last shared_ptr goes out of scope then the managed object gets deleted.
// 3. shared_ptr is threads safe and not thread safe. [what is this??]
//    a. control block is thread safe
//    b. managed object is not
// 4. There are three ways shared_ptr will destroy managed object.
//    a. If the last shared_ptr goes out of scope.
//    b. If you initialize shared_ptr with some other shared_ptr.
//    c. If you reset shared_ptr.
// 5. Reference count doesn't increase when we use reference or pointer of shared_ptr.
// 6. APIs provided by shared_ptr :
//  - use_count() : Returns the number of std::shared_ptr objects that share ownership of the managed object.
//  - reset() : This function resets the shared_ptr by releasing its ownership of the pointed object.If the shared_ptr was the last owner of the object, the object is deleted.
//  - reset(ptr) : Resets the std::shared_ptr to manage the object pointed to by ptr.
//  - release(): Releases ownership of the managed object and returns a pointer to it.
//  - get() : Returns a pointer to the managed object.
//  - operator->(): Returns a pointer to the managed object.
//  - operator*(): Dereferences the managed object.

// Good article: https://blog.devgenius.io/shared-pointer-and-implementation-in-c-7ac3d299769e
// https://www.udemy.com/course/beg-modern-cpp/learn/lecture/27006076#overview
// https://www.youtube.com/watch?v=1RtiiRpjq6w&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=35
// https://www.youtube.com/watch?v=Tp5-f9YAzNk (Dave's Garage)


#include <iostream>
#include <memory>

//Some Uder Defined Type
class CMyClass {
public:
    CMyClass() { std::cout << "CMyClass created" << std::endl; };
    ~CMyClass() { std::cout << "CMyClass destroyed" << std::endl; };
};

int main() {
    //std::shared_ptr<CMyClass> ptr1(new CMyClass());
    std::shared_ptr<CMyClass> ptr1 = std::make_shared<CMyClass>();
    //auto ptr1 = std::make_shared<CMyClass>();

    {
        //In a new scope, I share the resource
        std::shared_ptr<CMyClass> ptr2 = ptr1;

        //Reference count is updated
        std::cout << "Use count = " << ptr2.use_count() << std::endl; //2
        std::cout << "Use count = " << ptr1.use_count() << std::endl; //2
    } //ptr2 is freed here

    //Check updated reference count
    std::cout << "Use count = " << ptr1.use_count() << std::endl; //1

    std::cout << "We should see the destructor call as ptr1 is freed when main returns, because reference count becomes 0" << std::endl;
    return 0;
}



//=============================================================================

// https://www.youtube.com/watch?v=-dREJCf2ve4

//#include <iostream>
//#include <memory>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//class Foo {
//    int x;
//public:
//    Foo(int x) :x{ x } {}
//    int getX() { return x; }
//    ~Foo() { cout << "~Foo" << endl; }
//};
//
//void fun(std::shared_ptr<Foo> sp, int count) {
//    static std::mutex m1;
//    std::lock_guard<std::mutex> loc(m1);
//    cout << "thread:" << count << " " << sp.use_count() << endl;
//}
//
//int main() {
//    std::shared_ptr<Foo> sp(new Foo(100));
//    //std::shared_ptr<Foo> sp = make_shared<Foo>(100);
//    //auto sp = make_shared<Foo>(100);
//
//    cout << sp->getX() << endl;
//    cout << "Before: " << sp.use_count() << endl;
//    //std::shared_ptr<Foo> sp1 = sp; //Reference count incremented
//    ////std::shared_ptr<Foo>& sp1 = sp; //Reference count not incremented
//    ////std::shared_ptr<Foo>* sp1 = &sp; // //Reference count not incremented
//    //cout << "After: " << sp.use_count() << endl;
//    //cout << "After: " << sp1.use_count() << endl;
//
//    thread t1(fun, sp, 1), t2(fun, sp, 2), t3(fun, sp, 3);
//    t1.join(); t2.join(); t3.join();
//    return 0;
//}