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
	int hIndex(vector<int> &citations)
	{
		sort(citations.begin(), citations.end());

		int n = citations.size();
		for (int i = 0; i < n; i++) {
			if (citations[i] >= n - i)
				return n - i;
		}
		return 0;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif