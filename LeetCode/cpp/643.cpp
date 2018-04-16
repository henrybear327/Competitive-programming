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
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0, n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                sum += nums[i];
                if(i == k - 1)
                    ans = max(ans, sum);
            } else {
                sum += nums[i];
                sum -= nums[i - k];

                ans = max(ans, sum);
            }
        }

        return 1.0 * ans / k;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
