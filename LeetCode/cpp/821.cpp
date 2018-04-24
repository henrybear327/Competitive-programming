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
    vector<int> shortestToChar(string S, char C)
    {
        int n = S.length();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (S[i] == C) {
                dp[i] = 0;
                for (int j = 1; i + j < n || i - j >= 0; j++) {
                    bool cont = false;
                    if (i + j < n && S[i + j] != C) {
                        dp[i + j] = min(dp[i + j], j);
                        cont = true;
                    }

                    if (i - j >= 0 && S[i - j] != C) {
                        dp[i - j] = min(dp[i - j], j);
                        cont = true;
                    }

                    if (cont == false)
                        break;
                }
            }
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