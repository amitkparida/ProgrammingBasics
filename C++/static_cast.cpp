
//Why to use static_cast when implicit conversion is involved?
//Ans: Because C-Style cast is hard to find in code, but you can search static_cast keyword

//NOTES:
// 1. For compatible type conversion, such as float to int. 
// 2. For conversion operator and conversion constructors. 
// 3. To avoid unrelated pointer conversion. 
// 4. Avoids derived to private base class pointer conversion. 
// 5. Use for all up-cast but never use for confused down-cast because there are no runtime checks performed for static_cast conversions. 
// 6. Intensions are more clear in C++ style cast (express your intent better and make code review easier) 
// 7. Finding is easy. 
// 8. Error found at compile-time. 

#include <iostream>
#include <string>
using namespace std;


// 1. It performs implicit conversions between types.
 
int main() {
	float f = 3.5;
	int a;
	a = f;
	a = static_cast<int>(f);
}


//// 2. Use static_cast when conversion between types is provided through Conversion operator or Conversion Constructor
// 
//class Int {
//	int x;
//public:
//	Int(int x = 0) :x(x) {
//		cout << "Conversion Constructor" << endl;
//	}
//	
//	operator string() {
//		cout << "Conversion Operator" << endl;
//		return to_string(x);
//	}
//};
//
//int main() {
//	Int obj(3);
//
//	string str1 = obj;
//	obj = 20;
//
//	string str2 = static_cast<string>(obj);
//	obj = static_cast<Int>(30);
//}


//// 3. static_cast is more restrictive than C-Style.
////	EXAMPLE: char* to int* is allowed in C-style but not with static_cast
//
//int main() {
//	char c;				// 1 byte data
//	int* p = (int*)&c;	// 4 bytes data
//	*p = 5;				// No Compile-time error, but Runtime error (That's why dangerous)
//
//	//int* ip = static_cast<int*>(&c); //Compile-time Error, because not compatible pointer types 
//}


//// 4. static_cast avoid cast from derived to private base class pointer.
//
//class Base {};
//class Derived : private Base {};
//
//int main() {
//	Derived d1;
//	Base* bp1 = (Base*)&d1;					// Allowed at compile-time
//	//Base* bp2 = static_cast<Base*>(&d1);	// Not allowed at compile-time
//}


//// 5. Use for all upcasts, but never use for confused down cast.
//
//class Base {};
//class Derived1 : public Base {};
//class Derived2 : public Base {};
//
//int main() {
//	Derived1 d1;
//	Derived2 d2;
//
//	Base* bp1 = static_cast<Base*>(&d2);
//	Base* bp2 = static_cast<Base*>(&d1);
//
//	Derived1* d1p = static_cast<Derived1*>(bp2);
//	Derived2* d2p = static_cast<Derived2*>(bp1);
//}


//// 6. static_cast should be preferred when converting to void* OR from void*
//
//int main() {
//	int i = 10;
//	void* v = static_cast<void*>(&i);
//	void* ip = static_cast<int*>(v);
//}
