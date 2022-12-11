//Remove Duplicates from an unsorted array (of characters)

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

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



//Remove duplicates from a sorted array (Or Remove consecutive duplicates)
//From Quick Heap programs. 
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
    int i = 1, j = 1;

    for (i = 1; str[i]; i++)
    {
        if (str[i] != str[i - 1])
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    return str;
}





//Remove duplicates from sorted array (of integers)
//We can remove duplicates in a sorted array in 2 ways: using temporary array or using separate index

//Using temporary array
//Time Complexity : O(n)
//Auxiliary Space : O(n)
int removeDuplicatesSortedInteger(int arr[], int n)
{
    // Return, if array is empty or contains a single element
    if (n == 0 || n == 1)
        return n;

    int* temp = new int[n];
    int index = 0;

    // If current element is not equal to next element then store that current element in temp array
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[index] = arr[i];
            index++;
        }
    }

    // Store the last element as it was not stored previously (whether it is unique or repeated)
    temp[index] = arr[n - 1];
    index++; //index became size now

    // Modify original array
    for (int i = 0; i < index; i++)
        arr[i] = temp[i];

    return index; // return new size of modified array.
}


//Just maintain a separate index for same array as maintained for different array in above Method.
//Time Complexity : O(n)
//Auxiliary Space : O(1)
int removeDuplicatesSortedInteger1(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    // To store index of next unique element
    int index = 0;

    // Doing same as done in above Method. Just maintaining another updated index i.e. j
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] != arr[i + 1]) 
        {
            arr[index] = arr[i];
            index++;
        }
    }

    arr[index] = arr[n - 1];
    index++;

    return index; // return new size of modified array.
}

//Another way of using separate index
//Time Complexity : O(n)
//Auxiliary Space : O(1)
int removeDuplicatesSortedInteger2(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int index = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[index] = arr[i];
            index++;
        }
    }

    return index;
}




int main()
{
    char str[] = "aaaamitkummaar";
    int n = sizeof(str) / sizeof(str[0]);
    cout << removeDuplicate(str, n);

    std::sort(str, str + n - 1);
    cout << removeDuplicateSorted(str, n) << endl << endl;

    int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5 };
    n = sizeof(arr) / sizeof(arr[0]);
    n = removeDuplicatesSortedInteger1(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
