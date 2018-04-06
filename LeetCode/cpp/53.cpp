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
        int mx = INT_MIN;
        int sum = 0;
        for (auto i : nums) {
            sum += i;

            sum = max(sum, i); // BUG!
            mx = max(mx, sum);
        }

        return mx;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif