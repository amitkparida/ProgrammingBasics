
//reintepret_cast
// 
//NOTES:
//1. reinterpret_cast can perform dangerous conversions because it can typecast any pointer to any other pointer.
//2. reinterpret_cast is used when you want to work with bits.
//3. The result of a reinterpret_cast cannot safely be used for anything other than being cast back to its original type.
//4. we should be very careful when using this cast.
//5. if we use this type of cast then our code becomes non-portable (i.e. will not be compatible with a different CPU architectures).

#include<iostream>
using namespace std;

// 1. It can perform dangerous conversions because it can typecast any pointer to any other pointer.
 
class Mango {
public:
	void eatMango() { cout << "Eating Mango" << endl; }
};

class Banana{
public:
	void eatBanana() { cout << "Eating Banana" << endl; }
};

int main() {
	Banana* banana = new Banana();
	Mango* mango = new Mango();

	Banana* newbanana = reinterpret_cast<Banana*>(mango);
	newbanana->eatBanana();// Will print "Eating Banana", as this pointer passed to this method is of Banana type.
}


//// 2. It is used when you want to work with bits.
//
//struct MyStruct {
//	int x;
//	int y;
//	char c;
//	bool b;
//};
//
//int main() {
//	MyStruct s;
//	s.x = 5;
//	s.y = 10;
//	s.c = 'a';
//	s.b = true;
//
//	int* p = reinterpret_cast<int*>(&s);
//	cout << *p << endl; // It will print 5, as it points to the first 4 byte (i.e. 1st int member) of the structure.
//	
//	p++;
//	cout << *p << endl; // It will print 10, as now it points to y
//	
//	p++;
//	cout << *p << endl; // It will print a big integer, because it dereference 4 bytes (9th byte to 12th byte of the structure)
//	char* cp = reinterpret_cast<char*>(p); 
//	cout << *cp << endl; // It will print 'a'
//
//	++cp;
//	bool* bp = reinterpret_cast<bool*>(cp);
//	cout << *bp << endl; // It will print 1
//}
