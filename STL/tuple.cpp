
// TOPIC: std::tuple In C++

// SYNTAX:
// std::tuple< data_type1, data_type2, data_type3> tuple_name;

// NOTES:
// 0. A tuple is an object that can hold a number of elements. The elements can be of different data types. 
//    The elements of tuples are initialized as arguments in order in which they will be accessed. 
// 1. Operations on tuple :- 
//    a. get() : get() is used to access the tuple values and modify them, it accepts the index and tuple name as arguments 
//               to access a particular tuple element. 
//    b. make_tuple() : make_tuple() is used to assign tuple with values. The values passed should be in order with the 
//               values declared in tuple. 
//    c. tie() : The work of tie() is to unpack the tuple values into separate variables. There are two variants of tie(), 
//               with and without “ignore” , the “ignore” ignores a particular tuple element and stops it from getting unpacked. 

#include <iostream>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {

	tuple<int, int, int> t1(1, 2, 3);
	tuple<char, int, double, int, long long int> t2 = make_tuple('a', 2, 2.3, 1, 10000);

	// get 3rd element in tuple t1 and 1st element in tuple t2
	cout << get<2>(t1) << endl;
	cout << get<0>(t2) << endl;

	int a, b, d = 10, e = 5, f = 15;
	char c;
	tie(a, b, c) = make_tuple(4, 1, 'a'); // this is equilvalent to a=4; b=1 ; c='a'
	tie(a, b) = make_tuple(b, a);  // swapping b and a
	tie(d, e, f) = make_tuple(d + e + f, d + 2 * e, 10 * d); // d = d+e+f, e = d+2*e, f = 10*d
	// used macro to see values
	watch(d), watch(e), watch(f);
}