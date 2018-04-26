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
/*
[0,4,4,5,9]
[0,1,6,8,10]
*/
class Solution
{
public:
    int minSwap(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        int dp[n][2];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i][1] = 0x3f3f3f3f;

        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            // 0 no swap
            if (A[i - 1] < A[i] && B[i - 1] < B[i])
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            if (B[i - 1] < A[i] && A[i - 1] < B[i])
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);

            // 1 swap
            if (A[i - 1] < B[i] && B[i - 1] < A[i])
                dp[i][1] = min(dp[i][1], 1 + dp[i - 1][0]);
            if (B[i - 1] < B[i] && A[i - 1] < A[i])
                dp[i][1] = min(dp[i][1], 1 + dp[i - 1][1]);
        }

        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif