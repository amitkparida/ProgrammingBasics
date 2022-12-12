#include<iostream>
using namespace std;

int strStr(string str, string substr) {
	int index = str.find(substr);
	if (index != string::npos) {
		return index;
	}

	return -1;
}

int strStr1(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i <= n - m; i++) {
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



int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "for";

    int res = strStr1(s1, s2);
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