/*
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
[[1,1,1,1],[0,1,0,0],[0,1,1,1],[1,1,1,0],[0,1,1,0]]
[["1","1"],["1","1"]]
[["0","1","1","0","1"],["1","1","0","1","0"],["0","1","1","1","0"],["1","1","1","1","0"],["1","1","1","1","1"],["0","0","0","0","0"]]
[["1","1","1","1"],["1","1","1","1"],["1","1","1","1"]]
[["1","1","1","1"],["1","1","1","1"]]
*/
class Solution   // O(n^2m + nm^2)
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        int pre[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    pre[i][j] = 0;
                else
                    pre[i][j] =
                        (j - 1 >= 0 ? pre[i][j - 1] : 0) + (matrix[i][j] == '1' ? 1 : 0);
            }
        }

        int pre2[n][m];
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '0')
                    pre2[i][j] = 0;
                else
                    pre2[i][j] =
                        (i - 1 >= 0 ? pre2[i - 1][j] : 0) + (matrix[i][j] == '1' ? 1 : 0);
            }
        }

        //         for(int i = 0; i < n; i++) {
        //             for(int j = 0; j < m; j++)
        //                 cout << pre[i][j] << " ";
        //             cout << endl;
        //         }

        //          for(int i = 0; i < n; i++) {
        //             for(int j = 0; j < m; j++)
        //                 cout << pre2[i][j] << " ";
        //             cout << endl;
        //         }

        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        // 11010
        // 01110
        // 11110
        // what a case
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                {
                    // horizontal
                    int mn = pre[i][j];
                    int k = mn > 0 ? i - 1 : i; // first NOT
                    int val = mn;
                    for (; k >= 0; k--) {
                        if (pre[k][j] > 0) {
                            mn = min(mn, pre[k][j]);
                            val = max(val, mn * (i - k + 1));
                            continue;
                        }
                        break;
                    }

                    dp[i][j] = val;
                }

                {
                    // vertical
                    int mn = pre2[i][j];
                    int k = mn > 0 ? j - 1 : j; // first NOT
                    int val = mn;
                    for (; k >= 0; k--) {
                        if (pre2[i][k] > 0) {
                            mn = min(mn, pre2[i][k]);
                            val = max(val, mn * (j - k + 1));
                            continue;
                        }
                        break;
                    }

                    dp[i][j] = max(dp[i][j], val);
                }
                mx = max(mx, dp[i][j]);
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }

        return mx;
    }
};
