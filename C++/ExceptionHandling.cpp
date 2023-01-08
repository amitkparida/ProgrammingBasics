
// C++ Exceptions Handling Mechanism:
//
// try:
//   - creates a scope/block and the exception causing code appears here
//   - can contain other try-catch statements
//
// throw:
//   - throws an exception from the try block
//   - exception is object that is constructed in throw statement
//
// catch:
//   - handler that catches the exception object 
//   - should appear just after the try block
//   - multiple catch blocks can exist

// When exception is thrown in the middle of a function, the stack of that function is destroyed. That's called Stack Unwinding. 
// In that case, all the local stack variables will be destroyed, but the dynamically allocated (using new or malloc) variables 
// won't be deleted if the exception occurs before the delete calls.Therefore, you should use Smart Pointers instead of raw pointers.

// https://amitkparida.medium.com/structured-exception-handling-in-visual-c-618b9e792faa
// https://stackoverflow.com/questions/11938979/what-exception-classes-are-in-the-standard-c-library


#include <iostream>
using namespace std;

int devide(int i, int j) {
	// Throw C++ Software Exception if j == 0. 
	// If you don't check and throw here, you will get DevideByZero Hardware Exception when i/j is computed by CPU.
	if (j == 0) {
		throw std::invalid_argument("2nd argument can't be 0 as we can't devide by 0");
	}

	return i / j;
}

void devide_nested() {
	try {
		for (int i = 100; i > 0; i--) {
			devide(i, i / 10);
		}
	}
	catch (std::invalid_argument& e) {
		throw e; //you can rethrow the same exception 
		//throw std::runtime_error(e.what()); //you can rethrow different expetion with same message
		//throw std::exception("Some error occurred"); //you rethrow different expetion with different message 
	}
}


int main()
{
	//try {
	//	//Below errors are derived from std::exception calss
	// 
	//	throw std::invalid_argument("Invalid Argument error occurred");
	//	//throw std::runtime_error("Runtime error occurred");
	//	//throw std::logic_error("Logic error occurred");
	//	//throw std::overflow_error("Overflow error occurred");
	//	//throw std::underflow_error("Underflow error occurred");
	//	//throw std::range_error("Range error occurred");
	//	//throw std::length_error("Length error occurred");
	//}
	//catch(std::exception& e){
	//	cout << "Message: " << e.what() << endl;
	//	cout << "Type: " << typeid(e).name() << endl;
	//}
	//catch(...){
	//	cout << "An Exception occurred" << endl;
	//}
	//cout << endl;


	////You can also throw your own errors (int, char, string etc)
	//try {
	//	throw 10;
	//	//throw std::string("My Exception");
	//}
	//catch (int& i) {
	//	cout << i << endl;
	//}
	//catch (std::string& str) {
	//	cout << str << endl;
	//}
	//cout << endl;


	////int size = std::numeric_limits<int>::max();
	//int size = INT64_MAX;
	//try {
	//	int* p = new int[size];
	//}
	//catch (std::bad_alloc& e) {
	//	cout << "Message: " << e.what() << endl;
	//	cout << "Type: " << typeid(e).name() << endl;
	//}


	//devide(10, 0);

	try {
		devide(10, 0);
	}
	catch (std::exception& e) {
		cout << "Message: " << e.what() << endl;
		cout << "Type: " << typeid(e).name() << endl;
	}
	cout << endl;


	////Nested
	//try {
	//	devide_nested();
	//}
	//catch (std::exception& e) {
	//	cout << "Message: " << e.what() << endl;
	//	cout << "Type: " << typeid(e).name() << endl;
	//}
	//cout << endl;

	return 0;
}