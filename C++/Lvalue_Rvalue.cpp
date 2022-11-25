
//Every expression in C++ is either Lvalue or Rvalue expression.
//Lvalue: If you can take address of the expression then it is Lvalue, and they last extended period of time.
//Rvalue: Rvalues are such expression which you cannot take address of. They are temporary and don't exist after one line.


//In C++ there are two types of references -
//
// lvalue reference :
// 1. An lvalue is an expression that will appear on the left - hand side or on the right - hand side of an assignment.
// 2. Simply, a variable or object that has a name and memory address.
// 3. It uses one ampersand(&).
//
// rvalue reference :
// 1. An rvalue is an expression that will appear only on the right - hand side of an assignment.
// 2. A variable or object has only a memory address(temporary objects).
// 3. It uses two ampersands(&&).


#include <iostream>

//Returns r-value
int Add(int x, int y) {
	return x + y;
}

//Return l-value
int& Transform(int& x) {
	x *= x;
	return x;
}

void Print(int& x) {
	std::cout << "Print(int&)" << std::endl;
}

void Print(const int& x) {
	std::cout << "Print(const int&)" << std::endl;
}

void Print(int&& x) {
	std::cout << "Print(int &&)" << std::endl;
}

int main() {
	//x is lvalue
	int x = 10;

	//ref is l-value reference
	int& ref = x;

	//Transform returns an l-value
	int& ref2 = Transform(x);

	//Binds to function that accepts l-value reference
	Print(x); //Print(const int&)

	//rv is r-value reference
	int&& rv = 8;

	//Add returns a temporary (r-value)
	int&& rv2 = Add(3, 5);

	//Binds to function that accepts a temporary, i.e. r-value reference
	Print(3); //Print(int &&)

	return 0;
}

