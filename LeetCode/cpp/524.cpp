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

class Solution
{
public:
	string findLongestWord(string s, vector<string> &d)
	{
		// sort by candidate
		sort(d.begin(), d.end(), [](const string &a, const string &b) {
			if (a.length() == b.length())
				return a < b;
			return a.length() > b.length();
		});

		for (auto i : d) {
			int idx = 0;
			for (auto j : s) {
				if (i[idx] == j)
					idx++;
				if (idx == (int)i.length())
					return i;
			}
		}
		return "";
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif