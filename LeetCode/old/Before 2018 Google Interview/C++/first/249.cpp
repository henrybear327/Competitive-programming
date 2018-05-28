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
private:
	int getDiff(char b, char a)
	{
		int aa = a - 'a';
		int bb = b - 'a';

		return (bb - aa + 26) % 26;
	}

public:
	vector<vector<string>> groupStrings(vector<string> &strings)
	{
		map<vector<int>, vector<string>> ans;
		for (auto i : strings) {
			vector<int> signature;
			// if (i.length() == 0)
			// 	ans[signature].push_back(i);

			// signature.push_back(getDiff(i[0], 'a'));
			for (int j = 1; j < (int)i.length(); j++) {
				signature.push_back(getDiff(i[j], i[0]));
			}

			// cout << i << endl;
			// for (auto j : signature)
			// 	cout << j << " ";
			// cout << endl;
			ans[signature].push_back(i);
		}

		vector<vector<string>> ret;
		for (auto i : ans)
			ret.push_back(i.second);
		return ret;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif