//Remove Duplicates from an unsorted array (of characters)

#include <iostream>
#include <unordered_set>
using namespace std;

// Time Complexity : O(n * n), Auxiliary Space : O(1)
char* removeDuplicate(char str[], int n)
{
    // Used as index in the modified string
    int index = 0;

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
            str[index++] = str[i];
        }
    }

    return str;
}


// Using unordered_set. It does not keep the order of input elements.
// Time Complexity : O(nLogn), Auxiliary Space : O(n)
char* removeDuplicate1(char str[], int n)
{
    // Create a set using string characters excluding '\0'
   // unordered_set<char> s(str, str + n - 1);

    unordered_set<char> s;
    for (int i = 0; i < n - 1; i++) {
        s.insert(str[i]);
    }

    int i = 0;
    for (auto x : s) {
        str[i++] = x;
    }
    str[i] = '\0';

    return str;
}


int main()
{
    char str[] = "amitkumar";
    int n = sizeof(str) / sizeof(str[0]);
    cout << removeDuplicate1(str, n);
    return 0;
}


//Remove Duplicates from an unsorted string

