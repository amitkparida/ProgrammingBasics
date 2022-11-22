//C++ STL program to demonstrate use of std::max_element() and std::min_element() functions

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //an array
    int arr[] = { 100, 200, -100, 300, 400 };

    //a vector
    vector<int> v1{ 10, 20, 30, 40, 50 };

    //finding largest element from the array
    int result = *max_element(arr + 0, arr + 5);
    cout << "largest element of the array: " << result << endl;

    //finding largest element from the vector
    result = *max_element(v1.begin(), v1.end());
    cout << "largest element of the vector: " << result << endl;


    //finding smallest element from the array
    result = *min_element(arr + 0, arr + 5);
    cout << "Smallest element of the array: " << result << endl;

    //finding smallest element from the vector
    result = *min_element(v1.begin(), v1.end());
    cout << "Smallest element of the vector: " << result << endl;

    return 0;
}