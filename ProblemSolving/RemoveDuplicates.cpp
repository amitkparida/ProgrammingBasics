#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//Remove Duplicates from an unsorted array (of characters)

// Simple method
// Time Complexity : O(n * n), Auxiliary Space : O(1)
char* removeDuplicate(char str[], int n)
{
    int index = 0; // Used as index in the modified string

    // Traverse through all characters
    for (int i = 0; i < n; i++) {

        // Check if str[i] is present before it  
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j])
                break;
        }

        // If not present, then add it to result.
        if (j == i) {
            str[index] = str[i];
            index++;
        }
    }

    return str;
}


// Using unordered_set. It does not keep the order of input elements.
// Time Complexity : O(nLogn), Auxiliary Space : O(n)
char* removeDuplicate1(char str[], int n)
{
    // Create a set using string characters excluding '\0'
    unordered_set<char> s(str, str + n - 1);

    //unordered_set<char> s;
    //for (int i = 0; i < n - 1; i++) {
    //    s.insert(str[i]);
    //}

    int i = 0;
    for (auto x : s) {
        str[i++] = x;
    }
    str[i] = '\0';

    return str;
}

//Using unordered_map
//access time in unordered_map on is O(1) generally if no collisions occur and therefore it helps us check if an element exists in a string in O(1) time complexity with constant space.
char* removeDuplicate2(char* str, int n) {
    unordered_map<char, int> exists;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (exists[str[i]] == 0)
        {
            exists[str[i]]++;
            str[index] = str[i];
            index++;
        }
    }
    return str;
}


//Using std::string::find()
//Time Complexity: O(n)
//Auxiliary Space : O(n), where n is the size of the given string.
string removeDuplicate3(string str)
{
    string temp;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        // If ch is present in temp, it returns the index of ch, else it returns npos
        if (temp.find(ch) == std::string::npos)
        {
            temp += ch;
        }
    }
    return temp;
}

//Another method using std::string::find()
//Time Complexity : O(n)
//Auxiliary Space : O(n)
string removeDuplicate4(string str)
{
    string temp = "";
    temp += str[0];

    for (int i = 1; i < str.length(); i++) {
        if (!(temp.find(str[i]) < temp.length()))
            temp = temp + str[i];
    }
    return temp;
}



//Remove duplicates from a sorted array of chars (Or Remove consecutive duplicates)
//From Quick Heal programs. 
//Time Complexity : O(n^2)
//Auxiliary Space : O(1)
char* removeDuplicateSorted(char str[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        if (str[i] == str[i + 1])
        {
            //shift each characters to left
            for (int j = i; j < (n - 1); j++)
            {
                str[j] = str[j + 1];
            }
            n--;
            i--;
        }
    }

    str[n] = '\0';

    return str;
}


//Better solution
//Time Complexity : O(n)
//Auxiliary Space : O(1)
char* removeDuplicateSorted1(char* str)
{
    int i = 0;

    for (int j = 1; str[j]; j++)
    {
        if (str[i] != str[j])
        {
            str[i + 1] = str[j];
            i++;
        }
    }

    str[i + 1] = '\0';

    return str;
}



//Remove duplicates from sorted array (of integers)

//Optimal way of using separate index
//Time Complexity : O(n)
//Auxiliary Space : O(1)
int removeDuplicatesSortedInteger(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}


// Using unordered_set. 
// Time Complexity : O(nLogn), Auxiliary Space : O(n)
int removeDuplicatesSortedInteger1(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);

    //unordered_set<int> s;
    //for (int i = 0; i < n; i++) {
    //    s.insert(arr[i]);
    //}

    int i = 0;
    for (auto x : s) {
        arr[i++] = x;
    }

    return s.size();
}


#include<windows.h>
int main()
{
    char str[] = "aaaamitkummaar";
    int n = sizeof(str) / sizeof(str[0]);
    cout << removeDuplicate(str, n) << endl << endl;

    char str1[] = "aaaamitkummaar";
    std::sort(str1, str1 + n - 1);
    cout << removeDuplicateSorted1(str1) << endl << endl;

    int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5 };
    n = sizeof(arr) / sizeof(arr[0]);
    n = removeDuplicatesSortedInteger(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
