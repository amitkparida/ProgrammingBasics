// TOPIC: Map In C++

// NOTES:
// 1. Syntax: map<T1, T2> obj;  // where T1 is key type and T2 is value type.
// 2. std::map is associative container that store elements in key value combination
//    where key should be unique, otherwise it overrides the previous value.
// 3. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
// 4. It store key value pair in sorted order on the basis of key (assending/decending).
// 5. std::map is generally used in Dictionay type problems.

// EXAMPLE: Dictionary




#include <iostream>
#include <map>
using namespace std;

class Person{
 public:
    int age;
    string name;
    
    bool operator < (const Person& rhs) const { return age<rhs.age; }
    bool operator > (const Person& rhs) const { return age>rhs.age; }

    Person(int n):age(n) {
    }
};

int main() {
    map<Person, int, less<>> Map;
    Person p1(10), p2(20);
    Map[p1] = 100;
    Map[p2] = 200;

    for (auto& el1 : Map) {
        cout << el1.first.age << " " << el1.second << endl;
    }

    return 0;
} 