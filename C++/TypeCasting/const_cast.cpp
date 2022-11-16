
//NOTES:
// The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or references.
// where T must be a pointer, reference, or pointer-to-member type.
//
// BOTTOM LINE:
// NEVER USE THIS!!!
// 1. Use const_cast only when you have to.
// 2. Use const_cast only when the actual refereed object / variable is not const.
// 3. Use when we are dealing with 3'rd party library and some API want data in non-const form but we have it in const. 
// (actually we can not do anything in that case, but make sure that API is not changing our variable value)


#include<iostream>
using namespace std;

////1. When the actual referred object/variable is not const
//
//int main(){
//	const int a1 = 10;
//	const int *b1 = &a1;
//	int* d1 = const_cast<int*>(b1);
//	*d1 = 15; //Compiles fine, but may result in Invalid and Undefined Behaviour at runtime
//
//	cout << a1 << endl; // It will print 10, not 15, because compiler will optimize the code, and just write 10 instead of a1
//	cout << *d1 << endl;
//
//	int a2 = 20; // Origincal variable is not const
//	const int* b2 = &a2;
//	int* d2 = const_cast<int*>(b2); //removes the const-ness of b2 (i.e. points to int, not const int).
//	*d2 = 30; //Valid code
//
//	return 0;
//}


// 2. When we need to call some 3rd party library where it is taking variable/object as non-const but not changing that.

void thirdPartyLibrary(int* x) {
	int k = 10;
	cout << k + *x;
}

int main() {
	const int x = 20;
	const int* px = &x;
	thirdPartyLibrary(const_cast<int*>(px));
}