class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        // cache ok combinations
        bool ok[1 << n];
        memset(ok, false, sizeof(ok));
        for(int i = 0; i < (1 << n); i++) {
            int total = 0;
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1) {
                     total += tasks[j];
                }
            }
            
            if(total <= sessionTime) {
                ok[i] = true;
            }
        }
            
        int dp[1 << n];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < (1 << n); i++) {
            for(int j = i; j > 0; j = i & (j - 1)) {
                /*
                Discussion: https://codeforces.com/blog/entry/45223
                The effect of j = i & (j - 1)
                */
                
                if(ok[j]) {
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};
