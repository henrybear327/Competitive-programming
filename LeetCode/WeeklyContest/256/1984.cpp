class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int l = 0, r = k - 1;
        int ans = nums[r] - nums[l];

        for (; r < nums.size(); l++, r++) {
            ans = min(ans, nums[r] - nums[l]);
        }

        return ans;
    }
};
