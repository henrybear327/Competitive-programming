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
	void go(string &inp, vector<string> &res)
	{
		int n = inp.length();
		// no leading zero
		if (inp[0] != '0')
			res.push_back(inp);

		// no leading and trailing zero
		if (inp[0] != '0' && inp[n - 1] != '0') {
			for (int i = 0; i < n - 1; i++)
				res.push_back(inp.substr(0, i + 1) + "." + inp.substr(i + 1));
		}

		// leading zero, no trailing zero
		if (n > 1 && inp[0] == '0' && inp[n - 1] != '0') {
			res.push_back(inp.substr(0, 1) + "." + inp.substr(1));
		}
		// 0
		if (n == 1 && inp[0] == '0')
			res.push_back(inp);
	}

	void analyze(string &left, string &right, vector<string> &ans)
	{
		// cout << left << " " << right << endl;
		vector<string> l, r;
		go(left, l);
		go(right, r);
		if (l.size() > 0 && r.size() > 0) {
			for (auto i : l)
				for (auto j : r)
					ans.push_back("(" + i + ", " + j + ")");
		}
	}

public:
	vector<string> ambiguousCoordinates(string S)
	{
		vector<string> ans;
		S = S.substr(1, S.length() - 2);
		for (uint i = 0; i < S.length() - 1; i++) {
			string left = S.substr(0, i + 1);
			string right = S.substr(i + 1);
			analyze(left, right, ans);
		}

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif