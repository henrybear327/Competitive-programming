class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // two pointer will get WA
        // 1, -1, 1, -1 -> ans = 4
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_map<int, int> cnt;
        int sum = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            sum += cur;
            int diff = sum - k;
            if (cnt.count(diff) > 0)
                ans += cnt[diff];
            cnt[sum]++;
        }
        return ans;
    }
};