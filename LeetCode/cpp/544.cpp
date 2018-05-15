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
	string findContestMatch(int n)
	{
		vector<string> res;
		res.reserve(n / 2);
		for (int i = 0; i < n / 2; i++)
			res.push_back("(" + to_string(i + 1) + "," + to_string(n - i) + ")");
		n /= 2;
		// for (auto i : res)
		// 	cout << i << endl;
		while (n > 1) {
			vector<string> tmp;
            tmp.reserve(n / 2);
			for (int i = 0; i < n / 2; i++)
				tmp.push_back("(" + res[i] + "," + res[n - 1 - i] + ")");
			res = tmp;
			n /= 2;
		}

		return res[0];
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif