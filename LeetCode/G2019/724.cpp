class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return -1;

        int left[n], right[n];
        left[0] = nums[0];
        for (int i = 1; i < n; i++)
            left[i] = left[i - 1] + nums[i];
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] + nums[i];

        for (int i = 0; i < n; i++) {
            int lValue = i - 1 >= 0 ? left[i - 1] : 0;
            int rValue = i + 1 < n ? right[i + 1] : 0;
            if (lValue == rValue)
                return i;
        }
        return -1;
    }
};