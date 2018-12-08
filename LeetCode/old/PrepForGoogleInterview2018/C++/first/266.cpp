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
	bool canPermutePalindrome(string s)
	{
		unordered_map<char, int> cnt;
		for (auto i : s)
			cnt[i]++;

		unordered_map<int, int> freq;
		for (auto i : cnt)
			freq[i.second]++;

		int odd = 0;
		for (auto i : freq)
			if (i.first % 2 == 1)
				odd += i.second;
		return odd <= 1;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif