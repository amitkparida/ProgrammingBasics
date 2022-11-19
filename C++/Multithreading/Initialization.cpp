//Uniform initialization.:
#include<iostream>

int main() {
	int a1; //Uninitialized
	int a2 = 0;
	int a3(5); //Direct initialization. Not commonly used
	std::string s1;
	std::string s2("C++");

	char d1[8]; //Uninitialized
	char d2[8] = { '\0' }; 
	char d3[8] = {'a', 'b', 'c', 'd'}; //Aggregate initialization
	char d4[8] = {"abcd"};

	int b1{};//Value initialization. Initialized to default value, i.e. 0
	//int b2();// Not an initialization. This creates a function called B2 which returns int. This is called as "Most Vexing Parse"
	int b3{5};//Direct initialization.

	char e1[8]{};//Value initialization. Initializes array elements to their default value, i.e. 0
	char e2[8]{"Hello"};

	int* p1 = new int{};

	char* p2 = new char[8]{};
	char* p3 = new char[8]{"Hello"};
}

/*
1. Value initialization => T obj{};
2. Direct initialization => T obj(v);
3. Copy initialization => T obj = v;  //Avoid it with user defined objects
*/

/*
Advantage of Uniform initialization.
1. It forces initialization
2. You can use direct initialization for array types
3. It prevents narrowing conversions.
4. Uniform syntax for all types
*/