class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int cnt[50000] = {0};
        vector<int> left(50000, INT_MAX), right(50000, INT_MIN);
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            mx = max(mx, cnt[nums[i]]);

            left[nums[i]] = min(left[nums[i]], i);
            right[nums[i]] = max(right[nums[i]], i);
        }

        int ans = INT_MAX;
        for (int i = 0; i < 50000; i++) {
            if (cnt[i] == mx) {
                ans = min(ans, right[i] - left[i] + 1);
            }
        }
        return ans;
    }
};
