class Solution
{
public:
    // 0 0 0 0
    // -2 0 1 1 2
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3)
            return ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int l = i + 1, r = n - 1;
            // 0 ==? [i] + [l] + [r]
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else {
                    ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l - 1] == nums[l])
                        l++;
                }
            }
        }

        return ans;
    }
};