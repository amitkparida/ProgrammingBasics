// TOPIC: STL Algorithm Sort

// NOTES:
// 0. In C++ STL we have sort function which can sort in increasing and decreasing order.
// 1. Not only integral but user defind data can be sorted using this function.
// 2. Internally it uses IntroSort which is combination of QuickSort, HeapSort and InsertionSort.
// 3. By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time,
//    it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.
// 4. We can use parallel execution policy for better performance.


// TYPES:
// 1. Sorting integral data types
// 2. Sorting user defined data types
// 3. Sort using a function object
// 4. Sort using lambda expression


#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
using namespace std;

// 1. Sort with integral data types

//int main() {
//    std::vector<int> Vec{ 5,4,6,7,3,2,8,9,1 };
//    
//    //std::sort(std::execution::par, Vec.begin(), Vec.end());
//    std::sort(Vec.begin(), Vec.end());
//    for (auto elm : Vec) {
//        cout << elm << " ";
//    }
//    return 0;
//}


// 2. Sort with user defined data types

 //class Point {
 //public:
 //    int x;
 //    int y;
 //    
 //    Point(int x = 0, int y = 0) :x{ x }, y{ y } {}

 //    bool operator < (const Point& p1) {
 //        return (x + y) < (p1.x + p1.y);
 //    }
 //};

 //int main() {
 //    std::vector<Point> Vec{ {1,2}, {3,1}, {0,1} };
 //    
 //    std::sort(Vec.begin(), Vec.end());

 //    for (auto& e : Vec) {
 //        cout << e.x << " " << e.y << endl;
 //    }
 //    return 0;
 //}



// 3. sort using a function pointer
 
//bool customLess(pair<int, int> a, pair<int, int> b) {
//    return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
//}
//
//int main() {
//    std::vector<pair<int, int>> Vec{ {5, 4}, {6, 9}, {3, 2}, {8, 7}, {1, 4} };
//
//    std::sort(Vec.begin(), Vec.end(), customLess);
//    for (auto elm : Vec) {
//        cout << "{" << elm.first << ", " << elm.second << "}" << " ";
//    }
//    return 0;
//}


// 4. sort using a function object

//struct {
//    bool operator()(int a, int b) const
//    {   
//        return a < b;
//    }   
//} customLess;

 //int main() {
 //    std::vector<int> Vec{ 5,4,6,7,3,2,8,9,1 };
 //    
 //    std::sort(Vec.begin(), Vec.end(), customLess);
 //    for (auto elm : Vec) {
 //        cout << elm << " ";
 //    }
 //    return 0;
 //}



// 5. sort using lambda expression

int main() {
    std::vector<int> Vec{ 5,4,6,7,3,2,8,9,1 };

    //std::sort(Vec.begin(), Vec.end(), std::greater<int>()); //Descending 
    //std::sort(Vec.begin(), Vec.end(), std::less<int>()); //Ascending
    std::sort(Vec.begin(), Vec.end(), [](int a, int b) { return a < b; }); //Ascending

    for (auto elm : Vec) {
        cout << elm << " ";
    }
    return 0;
}


//Note: greater<>() is used in case of sort(). But greater<> is used in case of others
// 
// sort(Vec.begin(), Vec.end(), greater<int>()); 
// 
// priority_queue<int, vector<int>, greater<int>> minheap; 
