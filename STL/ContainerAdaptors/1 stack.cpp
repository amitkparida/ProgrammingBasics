// TOPIC: std::stack In C++ !

// NOTES:
// 0. std::stack class is a container adapter that gives the programmer the functionality of a stack.
// 1. Internally it uses std::deque STL container.
// 2. It is LIFO (last-in, first-out) data structure.
// 4. std::stack allows to push(insert) and pop(remove) only from back.

// FUNCTIONS PROVIDED:
// empty() – Returns whether the stack is empty – Time Complexity : O(1)
// size() – Returns the size of the stack – Time Complexity : O(1)
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
// pop() – Deletes the top most element of the stack – Time Complexity : O(1)

// PROGRAM:
#include <iostream>
#include <stack>
using namespace std;

//void print(stack<int> stk) {
//    while (!stk.empty()) {
//        cout << stk.top() << endl;
//        stk.pop(); // Remove from the back
//    }
//}
//
//int main() {
//    stack<int> stk;
//
//    stk.push(2);
//    stk.push(3);
//    stk.push(4);
//
//    print(stk);
//
//    return 0;
//}


//Reverse string using std::stack
void reverse(char* str)
{
	stack<char> s;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		s.push(str[i]);
	}

	for (int i = 0; i < len; i++) {  //Note that here i < s.size() will not work in the condition as size changes after each Pop().
		str[i] = s.top();
		s.pop();
	}
	//str[len] = '\0'; //not needed as str already has \0 at the end

	//int i = 0;
	//while (!s.empty()) {
	//	str[i++] = s.top();
	//	s.pop();
	//}
	////str[i] = '\0'; //not needed as str already has '\0' at the end
}

//Reverse print a string using std::stack
void reversePrint(char* str)
{
	stack<char> s;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		s.push(str[i]);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	//for (int i = 0; i < len; i++) {  //Note that here s.size() will not work in the condition as size changes after each Pop().
	//	cout << s.top();
	//	s.pop();
	//}
}

int main()
{
	char str[]{"Amit Kumar Parida"};
	printf("\nBefore reversing:	%s\n", str);
	reverse(str);
	printf("After reversing:	%s\n", str);

	reversePrint(str);
}



