// TOPIC: std::set<T>

// SYNTAX: std::set<T> obectName;

// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logirathmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (Ascending/Descending)


#include <iostream>
#include <set>
#include <string>
using namespace std;

 int main() {
     set<int> Set = { 1,5,2,4,4,3,2,5 }; // Elements will be sorted in ascending order. To get descending order, greater<> must be passed as 2nd argument. Passing less<> is optional if you need ascending order.
     //set<int, less<>> Set = { 1,5,2,4,4,3,2,5 }; // Elements will be sorted in ascending order. Same as above.  
     //set<int, greater<>> Set = { 1,5,2,4,4,3,2,5 }; // Elements will be sorted in descending order.  

     Set.insert(20);

     for(const auto& e: Set) {
         cout << e << endl;
     }
 }


 /*
//User defined datatype

class Person {
public:
    int age;
    string name;

    //If you want to store user defined data type in set then you have to provide compare functions so that set can store them in sorted order.
    bool operator < (const Person& rhs) const { return age < rhs.age; }
    bool operator > (const Person& rhs) const { return age > rhs.age; }

    Person(int inAge, const string& inName) :age(inAge), name(inName) {
    }
};

int main() {
    set<Person> Set = { {30, "Rupesh"}, {25, "Hitesh"}, {22, "Jhon"} };

    //set<Person> Set = { Person(30, "Rupesh"), Person(25, "Hitesh"), Person(22, "Jhon") };

    for (const auto& e : Set) {
        cout << e.age << " " << e.name << endl;
    }
    return 0;
}
*/