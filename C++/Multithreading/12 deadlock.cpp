
// Deadlock:
// If Thread1 and Thread2 acquire locks in different order, they will wait for each other forever resulting in deadlock situation.
// Fix: Thread1 and Thread2 should acquire locks in same order. Deadlock will not happen.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1;
std::mutex m2;

void Thread1() {
	m1.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m2.lock();

	cout << "Critical Section of Thread1" << endl;

	m2.unlock();
	m1.unlock();
}

void Thread2() {
	m2.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m1.lock();

	cout << "Critical Section of Thread2" << endl;

	m1.unlock();
	m2.unlock();
}

int main() {
	thread t1(Thread1);
	thread t2(Thread2);
	t1.join();
	t2.join();
	return 0;
}
