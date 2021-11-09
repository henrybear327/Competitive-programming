class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // can also binary search for min length
        int l = 0;
        int n = nums.size();
        int sum = 0;
        int mn = n + 1;
        for(int r = 0; r < n; r++) {
            sum += nums[r]; // [l, r]
            
            while(l <= r && sum >= target) {
                mn = min(mn, r - l + 1);
                
                sum -= nums[l];   
                l++;
            }
        }
        
        return mn == n + 1 ? 0 : mn;
    }
};
