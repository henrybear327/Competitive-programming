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
"++++"
"+++++"
"++++++"
"+++++++++"
"++++-++++++"
*/
class Solution
{
private:
	bool isLoser(string &s)
	{
		int len = s.length();
		for (int i = 0; i < len - 1; i++)
			if (s[i] == s[i + 1] && s[i] == '+')
				return false;
		return true;
	}

	bool dfs(string &s, bool myTurn)
	{
		if (isLoser(s))
			return myTurn ? false : true;

		int len = s.length();
		for (int i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1] && s[i] == '+') {
				s[i] = s[i + 1] = '-';
				int ret = dfs(s, !myTurn);
				s[i] = s[i + 1] = '+';

				if (myTurn == true) {
					if (ret == true) // my turn, any branch with all win, return true
						return true;
				} else {
					if (ret == false)
						return false; // if opponent makes any move that I can't win, return false
				}
			}
		}

		return myTurn ? false : true;
	}

public:
	bool canWin(string s)
	{
		return dfs(s, true);
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif