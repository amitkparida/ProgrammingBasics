
// I just prepared this file to put all variant of hashing in one file for better understanding


#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int findDuplicate(int arr[], int n) 
{
	//int freq[n + 1] = { 0 }; //not allowed in VC++
	int* freq = new int[n + 1]{0};

	for (int i = 0; i < n; i++) 
	{
		if (freq[arr[i]] == 0) 
		{
			freq[arr[i]] += 1;
		}
		else 
		{
			delete freq;
			return arr[i];
		}
	}

	delete freq;
	return 0;
}

// Using hashing (map)
int findDuplicate2(int arr[], int n) {
	unordered_map<int, int> umap;

	for (int i = 0; i < n; i++)
	{
		if (umap[arr[i]] == 0)
		{
			umap[arr[i]]++;
		}
		else
		{
			return arr[i];
		}
	}
	return 0;
}

void countFrequency(int arr[], int n)
{
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++)
	{
		if (visited[i] != true)
		{
			int count = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] == arr[j])
				{
					visited[j] = true;
					count++;
				}
			}
			cout << arr[i] << " " << count << endl;
		}
	}
}

void countFrequency1(int arr[], int n)
{
	unordered_map<int, int> mp;

	// Traverse through array elements and count frequencies
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	// Traverse through map and print frequencies
	for (auto x : mp) {
		cout << x.first << " " << x.second << endl;
	}
}

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


vector<int> twoSum2(vector<int>& nums, int target)
{
	vector<int> ans;
	unordered_map<int, int> umap;

	for (int i = 0; i < nums.size(); i++) {
		if (umap.find(target - nums[i]) != umap.end()) {
			ans.push_back(umap[target - nums[i]]);
			ans.push_back(i);
			return ans;
		}

		umap[nums[i]] = i;
	}

	return ans;
}




struct Node {
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int x) : data(x), next(NULL) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

class CLinkedList {
private:
	Node* head;

public:
	bool DetectLoop2();
	bool DetectLoop3();
	void RemoveLoop2();
	void RemoveLoop3();
};

bool CLinkedList::DetectLoop2() {
	unordered_map<Node*, bool> visited;

	Node* temp = head;
	while (temp) {
		if (visited[temp] == true) {
			return true;
		}

		visited[temp] = true;
		temp = temp->next;

	}

	return false;
}

bool CLinkedList::DetectLoop3() {
	unordered_set<Node*> s;

	Node* temp = head;
	while (temp) {
		// if (s.find(temp) != s.end()) {
		if (s.count(temp) > 0) {
			return true;
		}

		s.insert(temp);
		temp = temp->next;
	}

	return false;
}


//RemoveLoop using map or set. Extra O(n) space needed.
void CLinkedList::RemoveLoop2() {
	unordered_map<Node*, bool> visited;
	Node* prev = head;
	Node* temp = head;
	while (temp) {
		//if (visited.find(temp) == visited.end()) {
		if (visited[temp] == false) {
			visited[temp] = true;
			prev = temp;
			temp = temp->next;
		}
		else {
			// If node is already visited, then Loop detected. Make the previous node's next pointer NULL to remove the loop
			prev->next = NULL;
			return;
		}
	}
	return;
}

void CLinkedList::RemoveLoop3() {
	//Using set
	unordered_set<Node*> s;
	Node* prev = head;
	Node* temp = head;

	while (temp) {
		// if node not present in the set, insert it in the set
		if (s.count(temp) == 0) {
			s.insert(temp);
			prev = temp;
			temp = temp->next;
		}
		else { // if present, it is a cycle, make the previous node's next pointer NULL
			prev->next = NULL;
			return;
		}
	}
	return;
}


int main()
{
}