class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // two pointers
        int l = 0, sum = 0, ans = nums.size() + 1;
        for(int r = 0; r < nums.size(); r++) {
            // [l, r)            
            sum += nums[r];
            
            while(sum >= s) {
                ans = min(ans, r - l + 1);
                
                sum -= nums[l];
                l++;                    
            }
        }
        
        return ans == nums.size() + 1 ? 0 : ans;
    }
};
