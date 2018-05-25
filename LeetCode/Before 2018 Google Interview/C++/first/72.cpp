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
i runs word1
j runs word2
dp[i][j] updates when

1. word1[x] == word2[y], min(dp[i- 1][j -1], dp[i - 1][j], dp[i][j - 1])
2. insert: dp[i][j - 1] + 1
3. delete: dp[i - 1][j] + 1
4. replace: dp[i - 1][j - 1] + 1

for every dp[i][j], we can think of it as
"the min cost of transforming word1[i] to word2[j]"
so think of dp[i][j] as holding word2[j]

Try geek -> geeks, to compute (2, 2)
insert: (2, 1) = ge->g, and then (2,2) is g -> ge
delete: (1, 2) = g->ge, and then (2,2) is gee -> ge
replace: (1, 1) = g->g, and then ge -> ge
*/
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j- 1]; // no cost replace = same
                else {
                    // insert, delete, replace
                    dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
                }
            }
        return dp[n][m];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif