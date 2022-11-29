// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables can be used for two purposes:
//    a. Notify other threads
//    b. Wait for some condition
// 2. Condition variables allows running threads to wait on some conditions and once those conditions are met
//    the waiting thread is notified using :
//    a. notify_one();
//    b. notify_all();
// 3. You need mutex to use condition variable
// 4. If some thread wants to wait on some condition then it has to do these things:
//    a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);.
//    b. Execute wait, wait_for, or wait_until. The wait operations atomically realease the mutex
//       and suspend the execution of the thread.
//    c. When the condition variable is notified, the thread us awakened, and the mutex is atomically reacquired.
//       The thread should then check the condition and resume waiting if the wake up was spurious (illegitimate).
// 5. Condition variable is used to synchronize two or more threads.
// 6. Best use case of condition variable is Producer/Consumer problem.


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
	std::lock_guard<mutex> lg(m);
	balance += money;
	cout << "Amount added. Current balance: " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int money) {
	std::unique_lock<mutex> ul(m);
	cv.wait(ul, [] { return (balance != 0) ? true : false; });
	if (balance >= money) {
		balance -= money;
		cout << "Amount deducted: " << money << endl;
	}
	else {
		cout << "Amount can't be deducted, current balance us less than " << money << endl;
	}
	cout << "Current balance is: " << balance << endl;
}

int main() {
	std::thread t1(withdrawMoney, 500);
	std::thread t2(addMoney, 500);
	t1.join();
	t2.join();
	return 0;
}
