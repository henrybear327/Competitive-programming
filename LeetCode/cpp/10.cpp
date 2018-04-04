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

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) // init column 0
            dp[i][0] = false;
        for (int i = 2; i <= m; i++) // init row 0
            if (p[i - 1] == '*')
                // only deal with * case
                dp[0][i] = dp[0][i - 1] || dp[0][i - 2];

        for (int i = 1; i <= n; i++) { // for every possible prefix of input string
            for (int j = 1; j <= m; j++) { // run the regex against it
                if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (dp[i][j - 1]) // match 1
                        dp[i][j] = true;
                    else if (dp[i][j - 2]) // match 0
                        dp[i][j] = true;
                    else if (dp[i - 1][j] &&
                             ((s[i - 1] == p[j - 2]) || p[j - 2] == '.')) // match many
                        // aa match a*
                        // we look if a matches a* and a == a!
                        dp[i][j] = true;
                } else {
                    // single character match
                    // aaaa match a*
                    // at i = 2 j = 1, aa match a is a false
                    // since a match {} is false, by appending a to both sides won't get
                    // an true
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }

        /*
        for (int i = 0; i <= n; i++) {
            printf("%c ", i == 0 ? ' ' : s[i - 1]);
            if (i == 0)
                for (int j = 0; j <= m; j++)
                    printf("%c%c", j == 0 ? ' ' : p[j - 1], j == m ? '\n' : ' ');

            if (i == 0)
                printf("  ");
            for (int j = 0; j <= m; j++) {
                printf("%d%c", dp[i][j] == true ? 1 : 0, j == m ? '\n' : ' ');
            }
        }
        */
        return dp[n][m];
    }
};

#ifdef LOCAL
int main()
{
    {
        string s = "aaaa";
        string p = "a*";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "aaba";
        string p = "ab*a*c*a";
        cout << Solution().isMatch(s, p) << endl;
    }

    return 0;
}
#endif