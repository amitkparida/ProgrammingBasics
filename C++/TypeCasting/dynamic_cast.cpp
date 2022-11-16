
//TOPIC: dynamic_cast in c++
//
//NOTES :
//	0. dynamic_cast is used at run time to find out correct down-cast.
//	1. Need at least one virtual function in base class.
//	2. If the cast is successful, dynamic_cast returns a value of type new_type.
//	3. If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
//	4. If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.
//
//	BOTTOM LINE :
//	1. work only on polymorphic base class (at least one virtual function in base class) because it uses this information to decide about wrong down-cast.
//	2. it is used for up-cast (D to B) and down-cast (B to D), but it is mainly used for correct downcast.
//	3. using this cast has run time overhead, because it checks object types at run time using RTTI (Run Time Type Information).
//	4. if we are sure that we will never cast to wrong object then we should always avoid this castand use static_cast.

#include <iostream>
using namespace std;

class Base {
	//Atleast one virtual function is needed, to use dynamic_cast
	virtual void Print() { cout << "Base" << endl; }
};

class Derived1: public Base {
	void Print() { cout << "Derived1" << endl; }
};

class Derived2 : public Base {
	void Print() { cout << "Derived2" << endl; }
};

int main() {
	Derived1 d1;

	Base* bp = dynamic_cast<Base*>(&d1);

	//Below cast will fail because Base class pointer does not point to Derived2 object. 
	Derived2* dp2 = dynamic_cast<Derived2*>(bp);
	if (dp2 == nullptr) {
		cout << "FAIL" << endl;
	}
	else {
		cout << "SUCCESS" << endl;
	}

	//Below cast will succeed because Base class pointer points to Derived1 object. 
	Derived1* dp1 = dynamic_cast<Derived1*>(bp);
	if (dp1 == nullptr) {
		cout << "FAIL" << endl;
	}
	else {
		cout << "SUCCESS" << endl;
	}



	Base& rBase = dynamic_cast<Base&>(d1);

	//You will get bad_cast exception
	try {
		Derived2& rDerived2 = dynamic_cast<Derived2&>(rBase);
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}

	//You will not get exception as the cast will succeed
	try {
		Derived1& rDerived1 = dynamic_cast<Derived1&>(rBase);
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}

