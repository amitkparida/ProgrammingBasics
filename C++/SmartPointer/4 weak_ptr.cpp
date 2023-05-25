// TOPIC: Weak Pointer In C++

// NOTES:
// 0. If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then
//    weak_ptr is for non-ownership smart pointer. weak_ptr does not increase the reference count.
// 1. It actually reference to an object which is managed by shared_ptr.
// 2. A weak_ptr is created as a copy of shared_ptr.
// 3. We have to convert weak_ptr to shared_ptr in order to use the managed object.
// 4. It is used to remove cyclic dependency between two shared pointers.
// 5. APIs provided by weak_ptr :
//  - lock() : Returns a std::shared_ptr<T> object that shares ownership of the managed object with the std::weak_ptr<T> if the object still exists, or returns an empty shared_ptr if the object has been deleted.
//  - expired() : Returns true if the std::shared_ptr<T> that the std::weak_ptr<T> refers to has already been destroyed.

// Good article: https://blog.devgenius.io/weak-pointer-in-c-a960c9633c48
// https://www.udemy.com/course/beg-modern-cpp/learn/lecture/27006192#overview
// https://www.youtube.com/watch?v=dNaQoz1jCCg&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=36


#include <iostream>
#include <memory>

//Some Uder Defined Type
class CResource {
public:

    //If you declare below m_ptr as a shared_ptr, then reference count of ptr1 will become 2 when ptr1 is assigned to m_ptr in main().
    //When main() returns, reference count of ptr1 becomes 1 and hence the destructor ~CResource() will not be called (since the reference count > 0)
    
    //std::shared_ptr<CResource> m_ptr{}; // Note that this line won't increment the reference count or call the constructor because it's just a declaration.

    //To avoid above leak scenario in case of cyclic reference, we use weak_pointer
    //Reference count will not increase if weak_pointer references any resource. The destructor ~CResource() will be called when main() returns.
    std::weak_ptr<CResource> m_ptr{};

    CResource() { std::cout << "CResource created" << std::endl; };
    ~CResource() { std::cout << "CResource destroyed" << std::endl; };
};

int main() {
    std::shared_ptr<CResource> ptr1 = std::make_shared<CResource>(); // Reference count of ptr1 becomes 1
    ptr1->m_ptr = ptr1; // self/cyclic reference. Reference count of ptr1 becomes 2 if m_ptr is a shared_pointer, but remains 1 if m_ptr is a weak_pointer 
}


//=============================================================================================

//Some Uder Defined Type
//class CMyClass {
//public:
//    CMyClass() { std::cout << "CMyClass created" << std::endl; };
//    ~CMyClass() { std::cout << "CMyClass destroyed" << std::endl; };
//};
//
//int main() {
//    std::weak_ptr<CMyClass> ptr2;
//
//    {
//        std::shared_ptr<CMyClass> ptr1 = std::make_shared<CMyClass>();
//
//        {
//            //In a new scope, I share the resource
//            ptr2 = ptr1;
//
//            //Reference count is NOT updated
//            std::cout << "Use count = " << ptr2.use_count() << std::endl; //1
//            std::cout << "Use count = " << ptr1.use_count() << std::endl; //1
//        }
//
//        //Check updated reference count
//        std::cout << "Use count = " << ptr1.use_count() << std::endl; //1
//        std::cout << "Is weak_ptr (object that it points to) expired? " << ptr2.expired() << std::endl; //0
//
//        std::cout << "We should see the destructor call as ptr1 is freed here, and reference count becomes 0" << std::endl;
//    } // ptr1 will be destroyed
//
//    std::cout << "Use count = " << ptr2.use_count() << std::endl; //0
//    std::cout << "Is weak_ptr (object that it points to) expired? " << ptr2.expired() << std::endl; //1
//
//    return 0;
//}


//=============================================================================================


// https://www.youtube.com/watch?v=PC4XJyTP6I8

//int main() {
//
//    auto sharedPtr = std::make_shared<int>(100);
//    std::weak_ptr<int> weakPtr(sharedPtr);
//
//    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
//    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
//    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;
//
//    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
//        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
//        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
//    }
//    else {
//        std::cout << "Don't get the resource!" << std::endl;
//    }
//
//    weakPtr.reset();
//    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
//        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
//        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
//    }
//    else {
//        std::cout << "Don't get the resource!" << std::endl;
//    }
//    return 0;
//}



//=============================================================================================

/*
// https://youtu.be/PC4XJyTP6I8?t=671

struct Son;
struct Daughter;

struct Mother {
    ~Mother() {
        std::cout << "Mother gone" << std::endl;
    }
    void setSon(const std::shared_ptr<Son> s) {
        mySon = s;
    }
    void setDaughter(const std::shared_ptr<Daughter> d) {
        myDaughter = d;
    }
    std::weak_ptr<Son> mySon; // Break the cyclic reference with mother using weak_ptr
    std::shared_ptr<Daughter> myDaughter;
};

struct Son {
    Son(std::shared_ptr<Mother> m) :myMother(m) {}
    ~Son() {
        std::cout << "Son gone" << std::endl;
    }
    std::shared_ptr<const Mother> myMother;
};

struct Daughter {
    Daughter(std::shared_ptr<Mother> m) :myMother(m) {}
    ~Daughter() {
        std::cout << "Daughter gone" << std::endl;
    }
    std::shared_ptr<const Mother> myMother;
};

int main() {
    std::cout << std::endl;
    {
        std::shared_ptr<Mother> mother = std::shared_ptr<Mother>(new Mother);
        std::shared_ptr<Son> son = std::shared_ptr<Son>(new Son(mother));
        std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>(new Daughter(mother));
        mother->setSon(son);
        mother->setDaughter(daughter);
    }
    std::cout << std::endl;
}
*/

