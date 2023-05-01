// TOPIC: std::vector      

// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // Declarations/Initializations
    vector<int> vec;
    vector<int> vec1(5, 20); // size = 5, value of each element = 20
    vector<int> vec2 = { 1, 2, 3, 4, 5 }; // initializer list 
    vector<int> vec3{ 1, 2, 3, 4, 5 }; // uniform initialization
    vector<int> vec4(vec3.begin(), vec3.end()); // initialize a vector from another vector.

    //Initialize vector from an array.
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec5(arr, arr + n);

    //Initialize all elements with a particular value 
    vector<int> vec6(10); //size  = 10
    int value = 5;
    fill(vec6.begin(), vec6.end(), value);


    // Accessing Elements
    vec1[3] = 10;
    vec1.at(3) = 10;

    //Initialize by pushing elements one by one
    vec.reserve(11);
    for (int i = 0; i <= 10; ++i) {
        vec.push_back(i);
    }

    // Iterating vector using For Loop
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    
    cout << endl;

    // Iterating vector using Range-based For Loop
    for (const auto& elem : vec) {
        cout << elem << " ";
    }

    cout << endl;

    // Iterating vector using Iterator
    //for (auto it = vec.begin(); it != vec.end(); ++it) {
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    // Iterating vector using for_each
    for_each(vec.begin(), vec.end(),
        [](const auto& elem) {
            cout << elem << " ";
        });

    return 0;
}


// TOPIC: Best way to use vector in C++

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    vector<int> Vec;
//    Vec.reserve(32);
//    for (int i = 0; i < 32; ++i) {
//        Vec.push_back(i);
//        cout << "Size:" << Vec.size() << "   Capacity:" << Vec.capacity() << endl;
//    }
//    return 0;
//}



/*
// TOPIC: vector inside vector

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<vector<int>> graph;
    int edge, n1, n2;

    cin >> edge;
    graph.resize(edge);

    for (int i = 0; i < edge; ++i) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
    }

    for (const auto& e1 : graph) {
        for (const auto& e2 : e1) {
            cout << e2;
        }
        cout << endl;
    }

    return 0;
}
*/