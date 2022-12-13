
// Find all anagrams in a string
// Given two strings str and pattern, return an array of the the start indices of pattern's anagrams in str. You may return the answer in any order.
// An anagram is a string formed by rearranging the letters of a different string, typically using all the original letters exactly once.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Total Time complexity : O(mlogm) + O((n - m + 1)(m + mlogm + m)). Here mlogm for sorting pat. So O(mlogm)
//Space Complexity : O(m) As we are using Extra space for strings temp and sortedPattern
vector<int> findAnagrams(string str, string pattern)
{
    vector<int> ans{};
    int m = pattern.length();
    int n = str.length();

    string sortedPattern = pattern;
    sort(sortedPattern.begin(), sortedPattern.end());

    string temp;
    for (int i = 0; i < n - m + 1; i++) {
        temp = "";
        for (int k = i; k < i + m; k++) {
            //temp.push_back(str[k]);
            temp += str[k];
        }
        sort(temp.begin(), temp.end());

        if (temp == sortedPattern) {
            ans.push_back(i);
        }
    }

    return ans;
}

// https://www.youtube.com/watch?v=t4sDawyBqYc
//Time = O(N*256) = O(N)
//Space = O(256) = O(1)
vector<int> findAnagrams1(string str, string pat)
{
    vector<int> ans{};
    int len_pat = pat.size();
    int len_str = str.size();

    vector<int> hash_pat(256, 0);
    vector<int> hash_str(256, 0);

    if (len_str < len_pat) {
        return {};
    }

    // first window
    for (int i = 0; i < len_pat; i++) {
        hash_pat[pat[i]]++;
        hash_str[str[i]]++;
    }

    if (hash_pat == hash_str) {
        ans.push_back(0);
    }

    //Slide the window
    for (int i = len_pat; i < len_str; i++) {
        hash_str[str[i - len_pat]]--;
        hash_str[str[i]]++;

        if (hash_pat == hash_str) {
            ans.push_back(i - len_pat + 1);
        }
    }

    return ans;
}


int main()

{
    string str = "BACDGABCDA";
    string pattern = "ABCD";
    for (auto elm : findAnagrams1(str, pattern))
    {
        cout << elm << " ";
    }

    return 0;
}