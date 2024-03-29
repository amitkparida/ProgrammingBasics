
//NOTES:
// 1. In C++ (before C++11), if we do not write our own, then compiler automatically creates 
//    a default constructor, a copy constructor, an assignment operator and a destructor for every class.

// 2. Compiler creates 2 constructors by default - Default constructor and Copy constructor.
//    If you explicitly define any constructor in the class, compiler doesn't create the default constructor, 
//    however it creates the copy constructor.

// 3. If you explicitly define a parameterized or any other constructor in the class, 
//    compiler doesn't create the default constructor, however it creates the copy constructor. 
//    You will have to explicitly write a default constructor, if you want to create objects like, ClassName obj.

// 4. In C++11 and above, if we do not write our own, then compiler automatically creates 
//    a default constructor, a copy constructor, a copy assignment operator and a destructor, a move constructor 
//    and a move assignment operator for every class.

// 5. If you implement any of the above constructors (including default, copy constructor, copy assignment operator or destuctor),
//    the compiler won't synthesize the move constructor and move assignment operator. You will have to implement them as well.

// 6. If you implement any move operation (move constructor and move assignment operator), the compiler won't synthesize 
//    the default constructor, copy constructor or copy assignment operator. 
//    You will have to implement them as well (You can use "default" keyword for their default implementations).

// 7. Rule of Three vs Rule of Five in C++: https://www.tutorialspoint.com/Rule-of-Three-vs-Rule-of-Five-in-Cplusplus



// C++ program to demonstrate the Working of Copy constructor and Assignment Operator
// For explanation, read https://www.codeproject.com/articles/23533/copy-constructors-and-assignment-operators-just-te


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
    CString& operator=(const CString&); //Copy Assignment operator
    CString(CString&&); //Move constructor
    CString& operator=(CString&&); //Move Assignment operator

    void print() { // Function to print string
        cout << str << endl;
    } 
};

// In this the pointer returns the CHAR array in the same sequence of string object but with an additional null pointer '\0'
CString::CString(const char* inStr) {
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
CString::CString(const CString& rhs) {
    length = rhs.length;
    str = new char[length + 1];
    strcpy(str, rhs.str);
}

//Overload Copy Assignment operator. 
//Delete the contents of the existing string before assigning the new string.
//Use tempStr as we should not delete str first, then call str = new char[]. 
//Because if new throws exception, the object will be left in a bad state because str would have already been deleted.
CString& CString::operator=(const CString& rhs) {
    if (this == &rhs) { //handle self assignment
        return *this;
    }

    char* tempStr = new char[rhs.length + 1];
    strcpy(tempStr, rhs.str);
    delete[] str;
    str = tempStr;
    length = rhs.length;

    return *this;
}

//Overload Move Constructor
CString::CString(CString&& rhs) { //Notice that const is not used in parameter
    length = rhs.length;
    str = rhs.str;
    rhs.str = NULL; // Ownership of pointer transferred
}

//Overload Move Assignment operator. 
CString& CString::operator=(CString&& rhs) {
    if (this == &rhs) { //handle self assignment
        return *this;
    }

    delete[] str;
    str = rhs.str;
    rhs.str = NULL; // Ownership of pointer transferred
    length = rhs.length;

    return *this;
}


CString CreateString() {
    return *(new CString("Amit"));
}

int main()
{
    CString str1("Amit Kumar Parida");
    CString str2 = str1; //Copy constructor will be called.
    CString str3;
    str3 = str1; //Assignment operator will be called (when you assign one object to another existing object)

    CString str4{ CreateString() }; //Move constructor will be called when you try to copy/move temporary object. 
                                    //For optimization, most Modern compilers use Move/Copy Elision to omit calls
                                    //to Move/Copy constructors when you move/copy temporary object.
 
    CString str5;
    str5 = CreateString(); // Move Assignment operator will be called (when you assign one object to another existing object)

    //When main goes out of scope, the destructors of all the above objects will be called.
    //If we don't overload copy constructor or assignment operator, then it will cause multiple times delete of same underlying str array
    return 0;
}




//============================================================================================


/*
//Another Example

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
    CArray(const CArray& rhs) :size(rhs.size), data(new int[rhs.size]){
        copy(rhs.data, rhs.data + rhs.size, data);
    }

    //Overloading Assignment Operator
    CArray& operator=(const CArray& rhs){
        if (this == &rhs) { //handle self assignment
            return *this;
        }

        int* tempData = new int[rhs.size];
        copy(rhs.data, rhs.data + rhs.size, tempData);
        delete[] data;
        data = tempData;
        size = rhs.size;

        return *this;
    }

    //Overloading Move Constructor
    CArray(CArray&& rhs) :size(rhs.size), data(rhs.data) {
        rhs.data = NULL; //Transfer of pointer ownership
    }

    //Overloading Assignment Operator
    CArray& operator=(CArray&& rhs) {
        if (this == &rhs) { //handle self assignment
            return *this;
        }

        delete[] data;
        data = rhs.data;
        rhs.data = NULL;
        size = rhs.size;

        return *this;
    }
};

int main() {

}

*/

//===========================================================================================


/*
// Find the problem in the following program 

// Probem: Test1 destructor will be called when GlobalPrint() returns. This will delete the string.
// So next call t.Print() will print garbage. And the program will crash when main() returns because
// it will call the  Test1 destructor again causing a double delete of the string.

// Solution: Explicitly define deep copy constructor or 
// Pass the object by reference in void GlobalPrint(Test1& obj) to avoid copy constructor and destuctor calls

#include <iostream>
using namespace std;

class Test1
{
    char* m_strString;
public:
    Test1()
    {
        m_strString = new char[256];
        memset(m_strString, 0, 255);
    }

    void SetString(const char* str)
    {
        memcpy_s(m_strString, 256, str, 50);
    }

    ~Test1()
    {
        delete m_strString;
        m_strString = NULL;
        cout << "destructor called" << endl;
    }

    void Print()
    {
        cout << m_strString << endl;
    }

    //Test1(const Test1& obj)
    //{
    //	m_strString = new char[256];
    //	memcpy_s(m_strString,256,obj.m_strString,50);
    //}
};

//void GlobalPrint(Test1& obj)
void GlobalPrint(Test1 obj)
{
    obj.Print();
}

int main()
{
    Test1 t;
    t.SetString("Symantec");
    GlobalPrint(t);
    t.Print();
    return 0;
}
*/



//===========================================================================================



