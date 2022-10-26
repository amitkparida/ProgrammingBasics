//Auto Pointer implementation

#include<iostream>
using namespace std;

template<class T>
class smart_ptr {
	T* ptr;

public:
	explicit smart_ptr(T* p = 0) :ptr(p) {

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


//auto_ptr:
//Drawbacks of auto_ptr: Copying and assigning modifies the ownership of auto_ptr, 
//i.e. the source leaves the ownership and destination gets the ownership

//shared_ptr:
//Based is reference count model. Counter incremented each time a new pointer points to the resource.
//Decremented when the destructor of the object is called.





