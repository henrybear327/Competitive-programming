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

		int sameWithPrev = 0;
		int differFromPrev = k;
		int dp = sameWithPrev + differFromPrev;
		for (int i = 1; i < n; i++) {
			sameWithPrev =
			    differFromPrev; // extend all comb. of same with prev by extending
			// diff with prev with the ending color
			differFromPrev =
			    dp * (k - 1); // extend all comb. of diff from prev by using the (k -
			// 1) colors that differes with their ending

			dp = sameWithPrev + differFromPrev;
		}

		return dp;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif