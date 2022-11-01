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

int main() {
    map<string, int> Map; // Elements will be sorted in ascending order of the strings. To get descending order, greater<> must be passed as 3rd argument. Passing less<> is optional if you need ascending order. 
    //map<string, int, greater<>> Map; // Elements will be sorted in descending order of the strings.  
    Map["Amit"] = 30;
    Map["Sumit"] = 32;
    Map.insert(make_pair("Rohit", 35));

    ////Alternate ways to initialize the above map
    //map<string, int> Map = { make_pair("Amit", 30), make_pair("Sumit", 32), make_pair("Rohit", 35) };
    //map<string, int> Map = { {"Amit", 30}, {"Sumit", 32}, {"Rohit", 35} };

    for (auto& el : Map) {
        cout << el.first << " : " << el.second<< endl;
    }

    //Access using [] operator
    cout << Map["Sumit"] << endl;
}


/*
//User defined

#include <iostream>
#include <map>
using namespace std;

class Person{
 public:
    int age;
    string name;
    
    //comparision operators must be overloaded for user defined classes
    bool operator < (const Person& rhs) const { return age<rhs.age; }
    bool operator > (const Person& rhs) const { return age>rhs.age; }

    Person(int inAge, const string& inName) :age(inAge), name(inName) {
    }
};

int main() {
    map<Person, int, less<>> Map; //less<> is optional if you need ascending order. To get descnding order, greater<> must be passed as 3rd argument
    Person p1(30, "Amit"), p2(32, "Sumit");
    Map[p1] = 100;
    Map[p2] = 200;

    ////Alternate ways to initialize the above map
    //map<Person, int> Map = { make_pair(Person(30, "Amit"), 100), make_pair(Person(32, "Sumit"), 200) };
    //map<Person, int> Map = { {Person(30, "Amit"), 100}, {Person(32, "Sumit"),200} };
    //map<Person, int> Map = { {{30, "Amit"}, 100}, {{32, "Sumit"}, 200} };

    for (auto& el : Map) {
        cout << el.first.age << " " << el.second << endl;
    }

    return 0;
} 
*/

