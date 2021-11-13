class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //   1 -1 1 -1 1 -1, 0
        // 0 1  0 1  0 1  0 
        unordered_map<int, int> dp;
        dp[0] = 1;
        int pre = 0, ans = 0;
        for(auto &num: nums) {
            // pre - x = k -> x = num - k
            pre += num;
            ans += dp[pre - k];
            dp[pre]++;
        }
        
        return ans;
    }
};
