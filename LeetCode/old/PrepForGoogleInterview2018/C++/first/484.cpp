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
	vector<int> findPermutation(string s)
	{
		vector<int> ans;
		ans.reserve(s.length() + 1);
		int n = s.length();
		for (int i = 1; i <= n + 1; i++)
			ans.push_back(i);

		int left = 0, right = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'D') {
				right = i + 1;
			} else {
				reverse(next(ans.begin(), left), next(ans.begin(), right + 1));
				left = right = i + 1;
			}
		}

		reverse(next(ans.begin(), left), next(ans.begin(), right + 1));

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif