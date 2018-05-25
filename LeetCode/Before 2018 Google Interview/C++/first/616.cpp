#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
/*
sample case
"abcxyz123"
["abc","123"]
"aaabbcc"
["aaa","aab","bc"]
*/
class Trie
{
private:
	struct Node {
		bool hasEnding = false;
		unordered_map<char, Node *> nxt;
	};

	Node *head = new Node;

public:
	void addWord(string s)
	{
		Node *cur = head;
		for (auto i : s) {
			if (cur->nxt.count(i) == 0) {
				cur->nxt[i] = new Node;
			}
			cur = cur->nxt[i];
		}
		cur->hasEnding = true;
	}

	int walk(string s)
	{
		Node *cur = head;
		int step = 0;
		for (auto i : s) {
			if (cur->nxt.count(i) == 0)
				break;
			cur = cur->nxt[i];
			step++;
		}

		return cur->hasEnding ? step : 0;
	}
};


// checking can be performed the other way around
// for every word in dict, mark occurrence in s
// this is why KMP can be used since we can skip when comparing
class Solution
{
public:
	// trie checking
	string addBoldTag(string s, vector<string> &dict)
	{
		// for every start...
		// sort(dict.begin(), dict.end(),
		// [](const string &a, const string &b) -> bool {
		// 	return a.length() > b.length();
		// });
		Trie trie;
		for (auto i : dict) {
			trie.addWord(i);
		}

		vector<bool> ok(s.length(), false);
		int start = -1, end = -1; // [start, end]
		for (int i = 0; i < (int)s.length(); i++) {
			int ret = trie.walk(s.substr(i));
			if (ret > 0) {
				if (start == -1)
					start = i;
				end = max(end, i + ret - 1);
			}

			if (i == end) {
				for (int j = start; j <= end; j++)
					ok[j] = true;
				start = end = -1;
			}
		}

		string ans = "";
		bool active = false;
		for (int i = 0; i < (int)s.length(); i++) {
			if (active) {
				if (ok[i] == false) {
					ans += "</b>";
					active = false;
				}
			} else {
				if (ok[i] == true) {
					ans += "<b>";
					active = true;
				}
			}
			ans += +s[i];
		}

		if (active)
			ans += "</b>";
		return ans;
	}

	// brute force checking
	// string addBoldTag(string s, vector<string> &dict)
	// {
	// 	// for every start...
	// 	sort(dict.begin(), dict.end(),
	// 	[](const string &a, const string &b) -> bool {
	// 		return a.length() > b.length();
	// 	});

	// 	string ans = "";
	// 	int start = -1, end = -1; // [start, end]
	// 	for (int i = 0; i < (int)s.length(); i++) {
	// 		for (auto j : dict) {
	// 			if (s.substr(i, j.length()) == j) {
	// 				if (start == -1)
	// 					start = i;
	// 				end = max(end, i + (int)j.length() - 1);
	// 				break;
	// 			}
	// 		}

	// 		if (end == -1)
	// 			ans += s[i];
	// 		else if (i == end) {
	// 			ans += "<b>" + s.substr(start, end - start + 1) +
	// "</b>"; 			start = end = -1;
	// 		}
	// 	}

	// 	ans = regex_replace(ans, regex("</b><b>"), "");
	// 	return ans;
	// }
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif