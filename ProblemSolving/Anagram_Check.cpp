
// Check whether two Strings are anagram of each other

// An anagram of a string is another string that contains all the same characters once each, only the order of characters can be different. 
// For example, “abcd”and “dabc” are an anagram of each other.

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Sort the two given strings and compare, if they are equal then they are anagram of each other.
// Time Complexity : O(N* logN), For sorting.
// Auxiliary Space : O(1) as it is using constant extra space
bool isAnagram(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they cannot be anagram
    if (n1 != n2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}


//Using count array: Increment the value in count array for characters in str1 and decrement for characters in str2. 
//Finally, if all count values are 0, then the two strings are anagram of each other. 
//Time Complexity : O(n)
//Auxiliary Space : O(256) i.e.O(1), As constant space is used

#define NO_OF_CHARS 256
bool isAnagram1(char* str1, char* str2)
{
    int count[NO_OF_CHARS] = { 0 };
    int i;

    // For each character in input strings, increment/decrement count in the corresponding count array
    for (i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    // Check if both strings are of different length. 
    // Removing this condition will make the program return true for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
        return false;

    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++) {
        if (count[i])
            return false;
    }
    return true;
}



//Using Map: Put all characters of one String in Map and reduce them as they are encountered while looping over other the string. 
//Finally, if all count values are 0, then the two strings are anagram of each other. 
//Time Complexity : O(N)
//Auxiliary Space : O(1), constant space is used
bool isAnagram2(string a, string b)
{
    if (a.length() != b.length()) {
        return false;
    }
 
    unordered_map<char, int> Map;

    // Loop over all character of String a and put in HashMap.
    for (int i = 0; i < a.length(); i++) {
        Map[a[i]]++;
    }

    // Now loop over String b
    for (int i = 0; i < b.length(); i++) {
        // Check if current character already exists in HashMap
        if (Map.find(b[i]) != Map.end()) {
            Map[b[i]]--;
        }
        else {
            return false;
        }
    }

    // Loop over all keys and check if all keys are 0. If so it means it is anagram.
    for (auto elm : Map) {
        if (elm.second != 0) {
            return false;
        }
    }

    return true;
}


int main()
{
    string str1 = "graam";
    string str2 = "armag";

    if (isAnagram(str1, str2))
        cout << "The two strings are anagram of each other"
        << endl;
    else
        cout << "The two strings are not anagram of each "
        "other"
        << endl;
}
