class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int mul = nums[0];
        for (int i = 1; i < n; i++)
            ans[i] = mul, mul *= nums[i];
        mul = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            ans[i] *= mul, mul *= nums[i];

        return ans;
    }
};