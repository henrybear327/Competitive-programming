class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> cnt;
        cnt[0]++;
        int ans = 0;
        for(auto i : nums) {
            sum += i;
            // i - x = k -> i - k = x
            ans += cnt[sum - k];
            cnt[sum]++;
        }
        
        return ans;
    }
};
