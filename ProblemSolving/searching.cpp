
/*
Let say we have an array of numbers.In this array every element is dependent on its previous element by - 1, 0 or +1.

arr = [4, 3, 4, 5, 6, 7, 6, 5, 4, 3]
find = 7
5

arr = [4, 3, 4, 5, 6, 7, 6, 5, 4, 3]
find = 8
- 1

Find if the number is present or not, If present return the first occurrence index of the number else return -1 
*/

#include <iostream>
using namespace std;

//int main()
//{
//    int arr[]{ 4, 3, 4, 5, 6, 7, 6, 5, 4, 3 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    int x = 7;
//
//    int i = 0;
//    while (i < n) {
//        if (x - arr[i] == 0) {
//            cout << i << endl;
//            return i;
//        }
//        else {
//            i = i + (x - arr[i]);
//        }
//    }
//
//    cout << "not found";
//    return -1;
//}



//Search in an almost sorted array using Binary search :
// https://www.geeksforgeeks.org/search-almost-sorted-array/



// Find first and last positions of an element in a sorted array
//Time Complexity: O(n) 
//Auxiliary Space : O(1)
void findFirstAndLast(int arr[], int n, int x)
{
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (x == arr[i]) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first != -1)
        cout << x << ": First Occurrence = " << first << ", Last Occurrence = " << last << endl;
    else
        cout << "Not Found" <<endl;
}



//Using Binary Search
//Time Complexity: O(log n) 
//Auxiliary Space : O(1)

/* if x is present in arr[] then returns the index of FIRST occurrence of x in arr[0..n-1], otherwise returns -1 */
int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            high = mid - 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            // If arr[mid] is same as x, we update res and move to the left half.
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

/* If x is present in arr[] then returns the index of LAST occurrence of x in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            high = mid - 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            // If arr[mid] is same as x, we update res and move to the right half.
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}


//An approach using inbuilt functions:
//Time Complexity: O(log n)
//Auxiliary Space : O(1)
void findFirstAndLast1(int arr[], int n, int x)
{
    int first, last;

    // to store first occurrence
    first = lower_bound(arr, arr + n, x) - arr;
    // to store last occurrence
    last = upper_bound(arr, arr + n, x) - arr - 1;

    if (first == n) {
        first = -1;
        last = -1;
    }
    cout << x << ": First Occurrence = " << first << ", Last Occurrence = " << last << endl;
}


int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 8;

    findFirstAndLast1(arr, n, x);

    x = 2;
    cout << x;
    cout << ": First Occurrence = " << first(arr, x, n);
    cout << ", Last Occurrence = " << last(arr, x, n);

    return 0;
}