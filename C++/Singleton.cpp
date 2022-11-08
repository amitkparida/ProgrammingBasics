
#include <iostream>
#include <mutex>
#include <thread>
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
	CMySingleton() {};                                 // Private constructor defined
	CMySingleton(const CMySingleton&);                 // Prevent copy-construction, definition not required
	CMySingleton& operator=(const CMySingleton&);      // Prevent assignment, definition not required
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

CMySingleton2* CMySingleton2::pInstance = NULL;// initialize static pointer


//OR


//Thread safe
class CMySingleton3
{
public:
	static CMySingleton3* getInstance() {
		if (pInstance == NULL) //Double check to avoid locking if the object is already created
		{
			mtx.lock();
			if (pInstance == NULL) 
			{
				pInstance = new CMySingleton3;
			}
			mtx.unlock();
		}
		return pInstance; // address of sole instance
	}

protected:
	CMySingleton3() {};
	CMySingleton3(const CMySingleton3&);
	CMySingleton3& operator= (const CMySingleton3&);

private:
	static CMySingleton3* pInstance;
	static mutex mtx;
};

CMySingleton3* CMySingleton3::pInstance = NULL;// initialize static pointer
mutex CMySingleton3::mtx;



void ThreadFun1() {
	CMySingleton3* p1 = CMySingleton3::getInstance();
	CMySingleton3* p2 = p1->getInstance();
}

void ThreadFun2() {
	CMySingleton3* p1 = CMySingleton3::getInstance();
	CMySingleton3* p2 = p1->getInstance();
}

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

	thread t1(ThreadFun1);
	thread t2(ThreadFun2);
	t1.join();
	t2.join();

	return 0;
}