class Solution {
private:
    int dp[202][202];
    int dfs(int left, int right) { // [left, right)        
        if(dp[left][right] != -1) // has answer
            return dp[left][right];
        
        if(right - left <= 1) {
            return dp[left][right] = 0; // finally got it right
        }
        
        // for all guesses
        int mn = INT_MAX;
        
        // 0 1 2 -> 2 / 2 = 1
        // 0 1 2 3 -> 3 / 2 = 1
        
        for(int i = left; i < right; i++) { // pick a number as the root of the guess            
            int cost = i; // not interested in guessing right, as this will not produce max cost

            int tmp = max(dfs(left, i), dfs(i + 1, right));

            mn = min(mn, cost + tmp);
        }
        
        dp[left][right] = mn;
        // cout << "dp[" << left << "][" << right << "]" << " " << dp[left][right] << endl;
        return dp[left][right] = mn;
    }
public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        
        return dfs(1, n + 1);
    }
};
