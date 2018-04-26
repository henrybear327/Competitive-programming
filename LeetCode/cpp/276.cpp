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
	int numWays(int n, int k)
	{
		if (n == 0)
			return 0;
		int different = k;
		int same = 0;

		for (int i = 1; i < n; i++) {
			int new_different = (k - 1) * (different + same);
			int new_same = different;

			different = new_different;
			same = new_same;
		}

		return different + same;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif