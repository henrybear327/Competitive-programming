class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int sum = 0;

        for(auto& num: nums) {
            sum += num;
            mx = max(mx, sum);
            if(sum < 0) {
                sum = 0;
            }
        }

        return mx;
    }
};
