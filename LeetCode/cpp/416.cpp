// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        bool dp[22222] = {0};
        dp[0] = 1;
        int sum = 0;
        for (auto i : nums) {
            sum += i;
            for (int j = 22221 - i; j >= 0; j--) {
                if (dp[j])
                    dp[j + i] = true;
            }
        }

        if (sum % 2 == 1)
            return false;
        return dp[sum / 2];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
