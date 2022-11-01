// TOPIC: Multimap In C++
// SYNTAX: multimap<T1, T2> obj; // where T1 is key type and T2 is value type.

// NOTES:
// 1. Multimap is an associative container that contains a sorted list of key-value pairs, 
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
//    Syntax: std::multimap<char, int, std::greater<>> Multimap;
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We dont have at() and [] functions to get element like we had in std::map.


#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    std::multimap<char, int> Multimap;
    Multimap.insert(make_pair('a', 1));
    Multimap.insert(make_pair('a', 2));
    Multimap.insert(make_pair('a', 3));
    Multimap.insert(make_pair('b', 4));
    Multimap.insert(make_pair('b', 5));

    // Iterate over multimap
    for(auto& elm: Multimap){
        cout << elm.first << " " << elm.second << endl;
    }
    cout << endl;

    cout << "Count of key 'a' = " << Multimap.count('a') << endl << endl;

    // Get all the pairs of given key
    //pair<multimap<char, int>::iterator, multimap<char, int>::iterator> range = Multimap.equal_range('a');
    cout << "All the pairs of key 'a': " << endl;
    auto range = Multimap.equal_range('a');
    for (auto& it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;

    auto ele = Multimap.lower_bound('a'); //returns the first 'a' 
    cout << "Lower bound of key 'a': " << ele->first << " " << ele->second << endl; //a 1

    auto ele1 = Multimap.upper_bound('a'); //returns the next element to the last 'a' 
    cout << "Upper bound of key 'a': " << ele1->first << " " << ele1->second << endl; //b 4

    return 0;
}