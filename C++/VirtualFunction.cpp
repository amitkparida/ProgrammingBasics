// TOPIC: Introduction To Virtual Function

// https://leetcode.com/discuss/study-guide/2827055/virtual-function-in-c/

// NOTES:
// 1. WHY to use virtual function?
//    a. To achieve dynamic polymorphism. Which is the ability to call Derived class function using Base class pointer or reference.

// 2. HOW to use virtual function?
//    a. By declaring function as virtual in Base class and overriding that function in Derived class.
//       (Function signature should be same in Base and Derived class)
//    b. Declaring a function as virtual in Base class is enough. The same function need not to be declared virtual in Derived class.
//    c. Virtual functions should be accessed using pointer(*) or reference(&) of Base class type to achieve run time polymorphism.

// ADITIONAL NOTES:
// 1. Virtual functions cannot be static and also cannot be a friend function of another class.
// 2. A class can have virtual destructor but can't have virtual constructor.
// 3. There are two types of virtual functions in C++.
//    a. Virtual Function
//    b. Pure Virtual Function


/*
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void eat() = 0;
};

class Cat : public Animal {
public:
    void eat() {
        cout << "Eating Non-veg" << endl;
    }
};

class Cow : public Animal {
public:
    void eat() {
        cout << "Eating Veg" << endl;
    }
};

int main() {
    Animal* a = new Cat();
    a->eat();
    return 0;
}

*/


// ================================================================================================


#include<iostream>
using namespace std;

class CBase
{
public:
	void M1()
	{
		cout << "In Method CBase::M1()" << endl;
	}
	virtual void M2()
	{
		cout << "In Method CBase::M2()" << endl;
	}
	virtual void M3()
	{
		cout << "In Method CBase::M3()" << endl;
	}
	virtual void M5()
	{
		cout << "In Method CBase::M5()" << endl;
	}
};

class CDerived :public CBase
{
public:
	virtual void M1()
	{
		cout << "In Method CDerived::M1()" << endl;
	}
	virtual void M2()
	{
		cout << "In Method CDerived::M2()" << endl;
	}
	virtual void M4()
	{
		cout << "In Method CDerived::M4()" << endl;
	}
	virtual void M5(int x)
	{
		cout << "In Method CDerived::M5(int x)" << endl;
	}
};

int main()
{
	//Carefully observe the call to M5() in each case 

	CBase* pBase = new CBase;
	pBase->M1();	//In Method CBase::M1()
	pBase->M2();	//In Method CBase::M2()
	pBase->M3();	//In Method CBase::M3()
	//pBase->M4();	//Compile Error as CBase::M4() is not there
	pBase->M5();	//In Method CBase::M5()
	cout << endl;


	CBase* pBase2 = new CDerived;
	pBase2->M1(); //In Method CBase::M1()
	pBase2->M2(); //In Method CDerived::M2()
	pBase2->M3(); //In Method CBase::M3()
	//pBase2->M4(); //Compile Error as CBase::M4() is not there
	pBase2->M5(); //In Method CBase::M5()
	//pBase2->M5(10);	//Compile Error as call resolves to CBase::M5(int) which is not there 
	cout << endl;


	CDerived* pDerived = new CDerived;
	pDerived->M1();	//In Method CDerived::M1()
	pDerived->M2();	//In Method CDerived::M2()
	pDerived->M3();	//In Method CBase::M3()
	pDerived->M4();	//In Method CDerived::M4()
	//pDerived->M5();	//Compile Error as call resolves to CDerived::M5() at compile time which is not there. 
					    //It can't call CBase::M5() as it's hidden by CDerived::M5(int x). It's called Method Hiding.
	pDerived->M5(10); //In Method CDerived::M5(int x)
	cout << endl;


	//CDerived* pDerived2 = new CBase; //Compile error as Derived class pointer can't point to Base class object

	return 0;
}


// ============================================================================================


/*
#include <iostream>
using namespace std;

class A {
public:
	void f1() { cout << "A::f1()" << endl; }
	virtual void f2() { cout << "A::f2()" << endl; }
	virtual void f3() { cout << "A::f3()" << endl; }
	virtual void f4() { cout << "A::f4()" << endl; }
};

class B : public A {
public:
	void f1() { cout << "B::f1()" << endl; }
	void f2() { cout << "B::f2()" << endl; }
	void f4(int x) { cout << "A::f4(int x)" << endl; } //Note that this has a argument, and it is not virtual. It hides the A::f4()
	void f5() { cout << "A::f5()" << endl; }
};

int main() {
	A* p;
	B o2;
	p = &o2;

	p->f1(); //A, (Early binding)
	p->f2(); //B, (Late binding)
	p->f3(); //A, (Late binding)
	p->f4(); //A, (Late binding)
	//p->f4(10); //Compile Error as call resolves to A::f4(int) at compile time which is not there (Early binding)
	//p->f5();  //Compile Error as call resolves to A::f5() which is not there (Early binding)
}
*/


