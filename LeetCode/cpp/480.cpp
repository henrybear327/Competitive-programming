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
	multiset<int> left, right;
	void insert(int num)
	{
		// cout << "insert" << endl;
		left.insert(num);
		balance();
	}

	void remove(int num)
	{
		// cout << "remove" << endl;
		auto it = left.find(num);
		if (it != left.end()) {
			left.erase(it);
		} else {
			it = right.find(num);
			if (it != right.end()) {
				right.erase(it);
			}
		}
		// cout << "Call balance" << endl;
		balance();
	}

	void balance()
	{
		// balance size
		// cout << "balance size" << endl;
		while (left.size() < right.size()) {
			left.insert(*right.begin());
			right.erase(right.begin());
		}

		while (left.size() - right.size() > 1) {
			right.insert(*left.rbegin());
			left.erase(prev(left.end(), 1));
		}

		// maintain increasing property
		// cout << "balance <=" << endl;
		while (left.size() > 0 && right.size() > 0 &&
		       *left.rbegin() > *right.begin()) {
			int s1 = *left.rbegin();
			int s2 = *right.begin();
			left.erase(prev(left.end(), 1));
			right.erase(right.begin());

			left.insert(s2);
			right.insert(s1);
		}
	}

	double query()
	{
		if ((left.size() + right.size()) % 2 == 0) {
			return (1.0 * *left.rbegin() + 1.0 * *right.begin()) / 2;
		} else {
			return *left.rbegin();
		}
	}

public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k)
	{
		vector<double> ans;
		int n = nums.size();

		for (int i = 0; i < k; i++)
			insert(nums[i]);
		ans.push_back(query());

		for (int i = k; i < n; i++) {
			// cout << i << endl;
			remove(nums[i - k]);
			insert(nums[i]);
			ans.push_back(query());
			// cout << i << endl;
		}

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	vector<int> inp{2147483647, 1, 2, 3, 4, 5, 6, 7, 214748364};
	auto ret = Solution().medianSlidingWindow(inp, 2);
	for (auto i : ret)
		cout << i << endl;
	return 0;
}
#endif