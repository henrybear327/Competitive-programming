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
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= num; i++) {
            dp[i] = i % 2 == 0 ? dp[i / 2] : dp[i / 2] + 1;
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
