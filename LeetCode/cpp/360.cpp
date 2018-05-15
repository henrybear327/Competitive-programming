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
	int aa, bb, cc;
	int cal(int x)
	{
		return aa * x * x + bb * x + cc;
	}

	bool cmp(int l, int r)
	{
		if (aa > 0)
			return l > r;
		return l < r;
	}

public:
	vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c)
	{
		vector<int> ans;
		ans.reserve(nums.size());
		aa = a;
		bb = b;
		cc = c;

		if (nums.size() == 0)
			return ans;

		int left = 0, right = (int)nums.size() - 1;
		while (left < right) {
			int l = cal(nums[left]);
			int r = cal(nums[right]);

			// cout << left << " " << right << endl;
			// cout << l << " " << r << endl;

			if (cmp(l, r)) {
				left++;
				ans.push_back(l);
			} else {
				right--;
				ans.push_back(r);
			}
		}

		ans.push_back(cal(nums[left]));

		if (a > 0)
			reverse(ans.begin(), ans.end());

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif