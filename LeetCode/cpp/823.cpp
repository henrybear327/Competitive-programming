#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

const int MOD = 1e9 + 7;
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

typedef long long ll;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &A)
    {
        sort(A.begin(), A.end());

        int n = A.size();
        unordered_map<int, ll> dp;
        for (auto i : A)
            dp[i] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] > 0) // OOPS!!
                    continue;
                int target = A[i] / A[j];
                if (dp.count(target) > 0) {
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[target] % MOD) % MOD;
                }
            }
        }

        int ans = 0;
        for (auto i : dp)
            ans = (ans + i.second) % MOD;
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    vector<int> inp{2, 4, 5, 10};
    cout << Solution().numFactoredBinaryTrees(inp) << endl;
    return 0;
}
#endif