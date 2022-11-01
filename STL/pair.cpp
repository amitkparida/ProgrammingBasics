// TOPIC: std::pair In C++

// SYNTAX:
// std::pair<T1, T2> obj;

// NOTES:
// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.

#include <iostream>
#include <vector>
using namespace std;

void print(std::pair<int, int>& obj) { cout << obj.first << " " << obj.second << endl; }

int main()
{
    {
        pair<int, int> obj(10, 20);
        print(obj);
    }

    {
        pair<int, int> obj = make_pair(10, 20);
        print(obj);
    }

    {
        vector<pair<string, int>> list;
        list.push_back(make_pair("Rupesh", 30));
        list.push_back(make_pair("Hitesh", 28));
        list.push_back(pair<string, int>("Bhupendra", 22)); //Note the difference here
        list.push_back(pair<string, int>("Sagar", 18));

        for (auto& elm : list) {
            cout << elm.first << " " << elm.second << endl;
        }
    }

    return 0;
}