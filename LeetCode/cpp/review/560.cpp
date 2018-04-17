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
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> pre;
        pre[0]++;
        int sum = 0, ans = 0;
        for (auto i : nums) {
            sum += i;
            if (pre.count(sum - k) > 0)
                ans += pre[sum - k];

            pre[sum]++;
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
