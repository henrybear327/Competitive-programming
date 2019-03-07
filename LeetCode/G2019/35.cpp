class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int l = -1, r = nums.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (target <= nums[mid])
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};