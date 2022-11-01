// TOPIC: Emplace In STL

// 1. All the containers supports insert and emplace operation to store data. 
// 2. Emplace is used to construct object in-place and avoids unnecessary copy of objects.
// 3. Insert and Emplace is equal for premetive data types but when we deal with heavy objects
//    we should use emplace if we can for efficiency.

#include <iostream>
#include <set>
using namespace std;

class A {
public:
    int x;
    A(int x = 0) : x{ x } { cout << "Default Constructor called" << endl; };
    A(const A& rhs) { x = rhs.x; cout << "Copy Constructor called" << endl; }
};

bool operator < (const A& lhs, const A& rhs) { return lhs.x < rhs.x; }

int main() {
    set<A> Set;
    
    Set.insert(10); // Calls both Defalut and Copy constructor
    cout << endl;
    
    Set.emplace(20); // Doesn't call Copy constructor. Calls only default constructor
    cout << endl;

    for (auto& elm : Set) {
        cout << elm.x << endl;
    }

    return 0;
}