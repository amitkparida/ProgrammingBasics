
//For explanation, read From: https://www.codeproject.com/articles/23533/copy-constructors-and-assignment-operators-just-te


// C++ program to demonstrate the Working of Copy constructor
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string.h>
using namespace std;

class CString {
private:
    char* str;
    size_t length; 

public:
    CString(const char* inStr = NULL); // Default/Parameterized constructor
    ~CString() { delete[] str; } // Destructor
    CString(const CString&); // Copy constructor
    CString& operator=(const CString&); //Assignment operator

    void print() { // Function to print string
        cout << str << endl;
    } 
};

// In this the pointer returns the CHAR array in the same sequence of string object but with an additional null pointer '\0'
CString::CString(const char* inStr)
{
    if (inStr == NULL) {
        length = 0;
        str = NULL;
    }
    else {
        length = strlen(inStr);
        str = new char[length + 1];
        strcpy(str, inStr);
    }
}

//Overload Copy Constructor
CString::CString(const CString& rhs)
{
    length = rhs.length;
    str = new char[length + 1];
    strcpy(str, rhs.str);
}

//Overload Assignment operator. Delete the contents of the existing string before assigning the new string.
//Use tempStr as we should not delete str first, then call str = new char[]. 
//Because if new throws exception, the object will be left in a bad state because str would have already been deleted.
CString& CString::operator=(const CString& rhs) {
    if (this != &rhs) { //handle self assignment
        char* tempStr = new char[rhs.length + 1];
        strcpy(tempStr, rhs.str);
        delete[] str;
        str = tempStr;
        length = rhs.length;
    }

    return *this;
}

int main()
{
    CString str1("Amit Kumar Parida");
    CString str2 = str1; //Copy constructor will be called
    CString str3;
    str3 = str1; //Assignment operator will be called (when you assign one object to another existing object)

    //When main goes out of scope, the destructors of all the above objects will be called.
    //If we don't overload copy constructor or assignment operator, then it will cause multiple times delete of same underlying str array
    return 0;
}


//============================================================================================


/*
//Copy constructor and Assignment operator

#include <iostream>
using namespace std;

class CArray {
    int* data;
    int size;

public:

    ////the implicit copy constrctor, supplied by compiler
    //CArray(const CArray& other) : size(other.size), data(other.data) {
    //} 

    //Overloading Copy Constructor
    CArray(const CArray& other) :size(other.size), data(new int[other.size]){
        copy(other.data, other.data + other.size, data);
    }

    //Overloading Assignment Operator
    CArray& operator=(const CArray& other){
        if (this != &other) {
            int* newdata = new int[other.size];
            copy(other.data, other.data + other.size, newdata);
            delete[] data;
            data = newdata;
            size = other.size;
        }
    }
};
*/


//===========================================================================================


// string size test
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = {1, 2, 3, 4};
//
//	wchar_t str[] = { L'a', L'm', L'i', L't' };
//	wchar_t str1[] = L"amit";
//	wstring str2 = str1;
//
//	cout << sizeof(arr) << endl;
//	cout << sizeof(str) << endl;
//	cout << sizeof(str1) << endl;
//	wcout << str2 << endl << str2.size() << endl << str2.length();
//}

