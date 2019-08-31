class Solution
{
    /*
    matrix
    1 1 1
    1 1 1
    1 1 1

    dp
    1 1 1
    1 2 2
    1 2 x

    To get x, we look at its up, left, upper-left values
    If you draw their squares out, you can see they will overlap into a 3*3
    */
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        int dp[n][m];
        memset(dp, 0, sizeof(dp));

        // init dp
        int mx = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == '1')
                dp[0][i] = 1, mx = 1;
        }
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1')
                dp[i][0] = 1, mx = 1;
        }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    int mn = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    mn += 1;

                    dp[i][j] = mn;
                    mx = max(mx, dp[i][j]);
                }
            }

        return mx * mx;
    }
};
