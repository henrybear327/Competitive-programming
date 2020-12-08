class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (const auto &i : nums) {
            cnt[i]++;
            if (cnt[i] * 2 > nums.size())
                return i;
        }

        return -1; // should not happen
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // 1 -> 0
        // 2 -> 1
        // 3 -> 1
        // 4 -> 2
        // 5 -> 2
        return nums[nums.size() / 2];
    }
};
*/
