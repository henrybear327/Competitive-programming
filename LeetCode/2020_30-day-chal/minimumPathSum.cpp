class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        dp[0][0] = grid[0][0];
        for(int i = 1; i < grid[0].size(); i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        
        for(int i = 1; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
            }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
