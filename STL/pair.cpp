// TOPIC: std::pair In C++

// SYNTAX:
// std::pair<T1, T2> obj;

// NOTES:
// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    pair<int, int> obj(10, 20);
    pair<int, int> obj1 = make_pair(10, 20);
    pair<int, int> obj2 = { 10, 20 };
    pair<int, int> obj3{ 10, 20 };
  
    cout << obj.first << " " << obj.second << endl;

    vector<pair<string, int>> list;
    list.push_back(make_pair("Amit", 30));
    list.push_back(pair<string, int>("Rohit", 22)); //Note the difference here
    list.push_back({ "Rakesh", 26 });

    for (auto& elm : list) {
        cout << elm.first << " " << elm.second << endl;
    }

    return 0;
}