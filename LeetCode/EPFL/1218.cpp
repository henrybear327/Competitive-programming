class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // bug on difference == 0
        unordered_map<int, int> dp;
        for(auto &num: arr) {
            if(dp.count(num - difference) == 1) { // num - diff -> num
                dp[num] = max(dp[num], dp[num - difference] + 1);
            } 
            
            if(dp[num] == 0) // delay init -> difference == 0 -> you will count self twice!
                dp[num] = 1;
        }
        
        int mx = 0;
        for(auto &tmp: dp)
            mx = max(mx, tmp.second);
        return mx;
    }
};
