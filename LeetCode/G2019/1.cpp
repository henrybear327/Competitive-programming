class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // input is not sorted

        unordered_map<int, int> has;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (has.find(diff) != has.end())
                return vector<int> {has[diff], i};
            has[nums[i]] = i;
        }

        return vector<int> {};
    }
};
