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
["hello","world"]
2
8
["a", "bcd", "e"]
3
6
["I", "had", "apple", "pie"]
4
5
["a"]
20000
20000
*/
class Solution
{
private:
    // int dfs(vector<string>& sentence, int rows, int
    // cols,vector<vector<int>>&dp, int si, int x, int y) {
    //     if(x >= rows || y >= cols)
    //         return 0; //?
    //
    //
    // }
public:
    int wordsTyping(vector<string> &sentence, int rows, int cols)
    {
        // vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // return dfs(sentence, rows, cols, dp, 0, x, y);

        int si = 0, sn = sentence.size();
        int ans = 0;
        int dp[sn];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < rows; i++) {
            if (dp[si] != -1) {
                ans += dp[si];
                si = (si + dp[si]) % sn;
            } else {
                int updateDP = -1, cnt = 0, j = 0;
                while (j < cols) {
                    // append the current word
                    if (j + (int)sentence[si].length() <= cols) {
                        if (j == 0)      // update dp
                            updateDP = si; // starting word
                        cnt++;

                        j = j + (int)sentence[si].length() + 1; // add space
                        ans++;
                        si = (si + 1) % sn;
                    } else { // can't append, next line
                        break;
                    }
                }
                if (updateDP != -1)
                    dp[updateDP] = cnt;
            }
        }
        return ans / sn;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
