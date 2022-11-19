// TOPIC: Different Types Of Thread Creation And Calling in C++11
// There are 5 different types of creating threads and calling callable objects in threads.

//NOTE:
//If we create multiple threads at the same time it does not guarantee which one will start first.

#include <iostream>	
#include <thread>
using namespace std;


// 1. Function Pointer
// this is the very basic form of creating threads.

void fun(int x) {
	while (x-- > 0) {
		cout << x << endl;
	}
}

int main() {
	std::thread t(fun, 10);
	t.join();
	return 0;
}


//// 2. Lambda Function
//// Example:
//
//int main() {
//	// we can directly inject lambda at thread creation time.
//	auto fun = [](int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	};
//
//	std::thread t(fun, 10);
//	t.join();
//
//	//OR 
//
//	std::thread t1([](int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//		}, 10);
//
//	t1.join();
//
//	return 0;
//}


//// 3. Functor (Function Object)
//
//class Base {
//public:
//	void operator ()(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//	std::thread t((Base()), 10);
//	t.join();
//	return 0;
//}


//// 4. Non-static member function
//
//class Base
//{
//public:
//	void run(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//	Base b;
//	std::thread t(&Base::run, &b, 10);
//	t.join();
//	return 0;
//}

// 5. Static member function

//class Base
//{
//public:
//	static void run(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//	std::thread t(&Base::run, 10);
//	t.join();
//	return 0;
//}