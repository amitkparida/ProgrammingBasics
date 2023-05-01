
//std::move
//Moves the elements in the range[first, last] into the range beginning at result.
//The value of the elements in the[first, last] is transferred to the elements pointed by result.
//After the call, the elements in the range[first, last] are left in an unspecified but valid state.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 7, 7, 7, 7, 7 };

    // Print elements
    std::cout << "Vector1 contains: ";
    for (int i = 0; i < vec1.size(); i++) {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\n";

    // Print elements
    std::cout << "Vector2 contains: ";
    for (auto elm : vec2) {
        std::cout << elm << " ";
    }
    std::cout << "\n\n";

    // Move first 4 element from vec1 to starting 2nd position of vec2
    std::move(vec1.begin(), vec1.begin() + 4, vec2.begin() + 1);

    // Print elements
    std::cout << "Vector2 contains after std::move function: ";
    for (auto it = vec2.begin(); it < vec2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}



// Another usage of std::move():
// It is used to convert an lvalue reference into the rvalue reference.
// Used to move the resources from a source object i.e. for efficient transfer of resources from one object to another.

//#include <iomanip>
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    std::string str = "Amit";
//    std::vector<std::string> v;
//
//    // Uses the push_back(const T&) overload, which means we'll incur the cost of copying str
//    v.push_back(str);
//    std::cout << "After copy, str is: " << str << '\n';
//
//    // Uses the rvalue reference push_back(T&&) overload, which means no strings will be copied; 
//    // instead, the contents of str will be moved into the vector. This is less expensive, but also means str might now be empty.
//    v.push_back(std::move(str));
//    std::cout << "After move, str is: " << str << '\n';
//
//    std::cout << "The contents of the vector are { " << std::quoted(v[0]) << ", " << std::quoted(v[1]) << " }\n";
//}
