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

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN, sum = 0;
        for (auto i : nums) {
            sum = max(sum + i, i);
            ans = max(ans, sum);
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
