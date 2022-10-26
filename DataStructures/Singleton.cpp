
#include <iostream>
using namespace std;

class CMySingleton
{
public:
	static CMySingleton& getInstance()
	{
		static CMySingleton singleton;
		return singleton;
	}

	// Other non-static member functions
private:
	CMySingleton() {};                                 // Private constructor
	CMySingleton(const CMySingleton&);                 // Prevent copy-construction
	CMySingleton& operator=(const CMySingleton&);      // Prevent assignment
};


//OR

class CMySingleton2
{
public:
	static CMySingleton2* getInstance() {
		if (pInstance == NULL) // is it the first call?
		{
			pInstance = new CMySingleton2; // create sole instance
		}
		return pInstance; // address of sole instance
	}

protected:
	CMySingleton2() {};
	CMySingleton2(const CMySingleton2&);
	CMySingleton2& operator= (const CMySingleton2&);

private:
	static CMySingleton2* pInstance;
};

CMySingleton2* CMySingleton2::pInstance = NULL;// initialize pointer

int main()
{
	CMySingleton* p1 = &CMySingleton::getInstance();
	CMySingleton* p2 = &p1->getInstance();
	CMySingleton* p3 = &CMySingleton::getInstance();
	CMySingleton& ref1 = CMySingleton::getInstance();
	CMySingleton& ref2 = CMySingleton::getInstance();

	CMySingleton2* p4 = CMySingleton2::getInstance();
	CMySingleton2* p5 = p4->getInstance();
	CMySingleton2* p6 = CMySingleton2::getInstance();
	CMySingleton2& ref3 = *CMySingleton2::getInstance();
	CMySingleton2& ref4 = *CMySingleton2::getInstance();

	return 0;
}