
// std::for_each() algorithm allows us to iterate over a given range of container elements 
// and perform operations (by calling a function) over each element.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintEven(int n) {
    if (n % 2 == 0)
        cout << n << ' ';
}

int main(void) {
    vector<int> v = { 1, 2, 3, 4, 5 };

    cout << "Vector contains following even numebrs:" << endl;
    for_each(v.begin(), v.end(), PrintEven);

    return 0;
}