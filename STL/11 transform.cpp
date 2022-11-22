
// 1. The transform() function in C++ sequentially applies an operation to the elements of an array(s) and 
//    then stores the result in another output array.
// 2. For an example if we want to perform square of each element of an array, and store it into other, 
//    then we can use the transform() function.
// 3. The transform function works in two modes.These modes are:
//    i. Unary operation mode
//    ii. Binary operation mode


//Unary Operation Mode:
//In this mode the function takes only one operator (or function) and convert into output.
//The operation is applied to each element in the input range, and the result is stored in the output array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int square(int x) {
//    return x * x;
//}
//int main() {
//    int input_arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int output_arr[10];
// 
//    //transform(input_arr, input_arr + 10, output_arr, [](int x) {return x * x; });
//    transform(input_arr, input_arr + 10, output_arr, square);
//    for (int i = 0; i < 10; i++) {
//        cout << output_arr[i] << " ";
//    }
//}


int main() {
    vector<int> inputVec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    vector<int> outputVec(inputVec.size());

    transform(inputVec.begin(), inputVec.end(), outputVec.begin(), [](int x) {return x * x; });
    for (int val : outputVec) {
        std::cout << val << " ";
    }
}




// Binary Operation Mode:
// 
// In this mode the it can perform binary operation on the given data. If we want to add elements of two different array, 
// then we have to use binary operator mode.
// 
// When applying a binary function, the transform() function takes the pointer to the starting and ending position
// of the first input array and pointer to the starting position of the second input array. The function also takes 
// the pointer to the start of the output array and pointer to the binary function that we want to apply to the two input arrays.

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int multiply(int x, int y) {
//    return x * y;
//}
//int main() {
//    int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int arr2[10] = { 54, 21, 32, 65, 58, 74, 21, 84, 20, 35 };
//    int output_arr[10];
//
//    transform(arr1, arr1 + 10, arr2, output_arr, multiply);
//    for (int i = 0; i < 10; i++) {
//        cout << output_arr[i] << " ";
//    }
//}


