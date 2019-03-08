class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        // case -1 -2 -3
        // case -1 2

        int sum = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, nums[i]);
            if (sum + nums[i] < 0) {
                sum = 0;
                continue;
            }

            sum += nums[i];
            if (sum < 0)
                sum = 0;
            ans = max(sum, ans);
        }
        return ans;
    }
};
