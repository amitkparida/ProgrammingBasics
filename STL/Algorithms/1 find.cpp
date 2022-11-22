// TOPIC: STL Algorithms

// NOTES:
// 0. STL algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating) 
// 1. Algorithms are applied to range of elements.
// 3. <algorithm> header is used to get all algorithms in stl.


// std::find():
// std::find() finds the first occurrence of the element in the given range. 
// It returns an iterator to the first element in the range [first,last) that compares equal to val. 
// If no such element is found, the function returns last.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::vector<int> Vec{ 4,3,5,2,6,1 };

    int val = 6;

    //std::vector<int>::iterator it = std::find(Vec.begin(), Vec.end(), val);
    auto it = std::find(Vec.begin(), Vec.end(), val);
    
    if (it == Vec.end()) {
        cout << "Element Not Found" << endl;
    }
    else {
        std::cout << "Element " << val << " found at position : ";
        std::cout << it - Vec.begin() << " (starting from zero index)" << endl;
    }

    return 0;
}

