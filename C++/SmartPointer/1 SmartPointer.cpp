// TOPIC: Introduction To Smart Pointers

// NOTES:
// 0. Smart pointer is a class which wraps a raw pointer, to manage the life time of the pointer.
// 1. The most fundamental job of smart pointer is to remove the chances of memory leak.
// 2. It makes sure that the object is deleted if it is not referenced any more.

// TYPES:
// 1. unique_ptr : 
//    Allows only one owner of the underlying pointer.
//	  Drawbacks of auto_ptr: Copying and assigning modifies the ownership of auto_ptr, 
//	  i.e. the source leaves the ownership and destination gets the ownership

// 2. shared_ptr : 
//    Allows multiple owners of the same pointer (Reference count is maintained).
//    Counter incremented each time a new pointer points to the resource.
//    Decremented when the destructor of the object is called.

// 3. weak_ptr : 
//    It is special type of shared_ptr which doesn't count the reference.

// https://www.linkedin.com/pulse/smartpointers-from-c11-onwards-amit-nadiger/


//Implementation of a basic Smart Pointer
#include<iostream>
using namespace std;

template<class T>
class smart_ptr {
	T* ptr;

public:
	explicit smart_ptr(T* p = NULL) :ptr(p) {

	}

	~smart_ptr() {
		delete ptr;
	}

	T& operator*() {
		return *ptr;
	}

	T* operator->() {
		return ptr;
	}
};


class CMyClass {
public:
	CMyClass() {
		cout << "Constructor called" << endl;
	}

	~CMyClass() {
		cout << "Destructor called" << endl;
	}
};

int main() {
	smart_ptr<CMyClass> pObj(new CMyClass);
	//No need to delete CMyClass as its destructor will automatically be called when main goes out of scope
}





////Implementation of int Smart Pointer
//#include<iostream>
//using namespace std;
//
//class smart_ptr {
//	int* ptr;
//
//public:
//	explicit smart_ptr(int* p = NULL) :ptr(p) {
//		cout << "smart_ptr created" << endl;
//
//	}
//
//	~smart_ptr() {
//		cout << "smart_ptr destroyed" << endl;
//		delete ptr;
//	}
//
//	int& operator*() {
//		return *ptr;
//	}
//
//	int* operator->() {
//		return ptr;
//	}
//};
//
//int main() {
//	smart_ptr pObj(new int);
//}


