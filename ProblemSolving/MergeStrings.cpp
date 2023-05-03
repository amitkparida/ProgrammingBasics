
// Merge strings alternatively
// https://leetcode.com/problems/merge-strings-alternately/

#include<iostream>
using namespace std;

string mergeAlternatively(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	
	string ans = "";
	int i = 0, j = 0;

	while (i < len1 && j < len2) {
		ans += str1[i++];
		ans += str2[j++];
	}

	while (i < len1) {
		ans += ans + str1[i++];
	}

	while (j < len2) {
		ans += str2[j++];
	}

	return ans;
}


string mergeAlternatively2(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();

	string ans = "";
	int i = 0, j = 0;

	while (i < len1 || j < len2) {
		if (i < len1) {
			ans += str1[i++];
		}

		if (j < len2) {
			ans += str2[j++];
		}
	}

	return ans;
}

int main() {
	string str1 = "amit";
	string str2 = "parida";

	cout << mergeAlternatively2(str1, str2);
}