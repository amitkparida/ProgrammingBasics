//Implementation of Queue using Stack

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
	stack<int> stk1;
	stack<int> stk2;

public:
	void add(int value);
	int remove();
};

void QueueUsingStack::add(int value) {
	stk1.push(value);
}

int QueueUsingStack::remove() {
	int value;
	if (stk2.empty() == false) {
		value = stk2.top();
		stk2.pop();
		return value;
	}

	while (stk1.empty() == false) {
		value = stk1.top();
		stk1.pop();
		stk2.push(value);
	}

	value = stk2.top();
	stk2.pop();
	return value;
}

// Testing code.
int main() {
	QueueUsingStack que;
	que.add(1);
	que.add(2);
	que.add(3);
	cout << "Queue remove : " << que.remove() << endl;
	cout << "Queue remove : " << que.remove() << endl;
	que.add(4);
	que.add(5);
	cout << "Queue remove : " << que.remove() << endl;

	return 0;
}

