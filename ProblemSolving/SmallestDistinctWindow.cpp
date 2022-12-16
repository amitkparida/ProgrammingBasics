
//Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
//For eg.A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

// SIMILAR Problems to practice:
// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
// https://www.youtube.com/watch?v=ZluoN6g6o0s


#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int findSubStringLength(string str) {
    set<char> s; 
    unordered_map<char, int> m;

    for (char c : str)
        s.insert(c);

    int ans = str.size();
    int n = s.size();

    int i = 0, j = 0;
    while (i < str.size())
    {
        m[str[i]]++;
        if (m.size() == n)
        {
            while (m[str[j]] > 1) 
                m[str[j++]]--;

            ans = min(ans, i - j + 1);
        }
        i++;
    }
    return ans;
}

int main()
{
    string str = "AABBBCBBAC";
    cout << findSubStringLength(str);
    return 0;
}