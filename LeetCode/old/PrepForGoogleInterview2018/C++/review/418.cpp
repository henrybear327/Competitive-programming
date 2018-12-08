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
    int wordsTyping(vector<string> &sentence, int rows, int cols)
    {
        int dp[sentence.size()];
        memset(dp, -1, sizeof(dp));

        int which = 0;
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            if (dp[which] == -1) {
                int j = 0;
                int dpi = which, cnt = 0;
                while (j < cols) {
                    if (j != 0)
                        j++; // space
                    if (j + (int)sentence[which].size() <= cols) {
                        j += sentence[which].size();
                        which = (which + 1) % sentence.size();
                        cnt++;
                        ans++;
                    } else {
                        break;
                    }
                }

                dp[dpi] = cnt;
            } else {
                ans += dp[which];
                which = (which + dp[which]) % sentence.size();
            }
        }

        return ans / sentence.size();
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif