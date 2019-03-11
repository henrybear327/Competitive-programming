class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int idx = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[idx - 1])
                nums[idx] = nums[i], idx++;
        }
        return idx;
    }
};