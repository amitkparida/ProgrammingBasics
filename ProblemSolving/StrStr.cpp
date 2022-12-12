// Check if a string is substring of another. If yes, return the index of the first occurrence, else return -1.

#include<iostream>
using namespace std;

//Using STL
//Time Complexity : O(M*N)
//Auxiliary space : O(1)
int strStr(string str, string substr) {
	int index = str.find(substr);
	if (index != string::npos) {
		return index;
	}

	return -1;
}

//Brute Force
//Time complexity : O(m*n) where mand n are lengths of s1and s2 respectively, Nested loops are used, outer from 0 to n – m and inner from 0 to m
//Auxiliary Space : O(1), As no extra space is required.
int strStr1(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i < n - m + 1; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (s2[j] != s1[i + j])
                break;
        }

        if (j == m) {
            return i;
        }
    }

    return -1;
}

//For char array inputs
int strStr2(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++) {
        int j;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s2[j] != s1[i + j])
                break;
        }

        if (s2[j] == '\0') {
            return i;
        }
    }

    return -1;
}


int strStr3(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int count = 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (count == m)
            break;

        if (s2[count] == s1[i])
        {
            count++;
        }
        else
        {
            // Special case where character preceding the i'th character is duplicate
            if (count > 0)
            {
                i -= count;
            }
            count = 0;
        }
    }
    return (count < m ? -1 : i - count);
}


int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "for";

    int res = strStr3(s1, s2);
    if (res == -1)
        cout << "Not present";
    else
        cout << "Present at index " << res << endl;


    char s3[] = "geeksforgeeks";
    char s4[] = "for";

    res = strStr2(s3, s4);
    if (res == -1)
        cout << "Not present";
    else
        cout << "Present at index " << res << endl;

    return 0;
}