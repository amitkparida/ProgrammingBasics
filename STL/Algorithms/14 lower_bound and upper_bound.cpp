
// lower_bound(first_iterator, last_iterator, x) � returns an iterator pointing to the first element in the range[first, last) 
// which has a value equal to or greater than �x�.

// upper_bound(first_iterator, last_iterator, x) � returns an iterator pointing to the first element in the range[first, last) 
// which has a value greater than �x�.


// C++ program to demonstrate working of lower_bound() and upper_bound().
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initializing vector with array values
    int arr[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    // Sort the array to make sure that lower_bound() and upper_bound() work.
    sort(vect.begin(), vect.end());

    auto q = lower_bound(vect.begin(), vect.end(), 20);

    auto p = upper_bound(vect.begin(), vect.end(), 20);

    cout << "The lower bound is at position: ";
    cout << q - vect.begin() << endl;

    cout << "The upper bound is at position: ";
    cout << p - vect.begin() << endl;

    return 0;
}

//Output
//The lower bound is at position : 3
//The upper bound is at position : 5