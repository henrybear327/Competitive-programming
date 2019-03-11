class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();
        bool used[n] = {false};
        long long int mx = LLONG_MIN, globalMX = LLONG_MIN;
        for (int i = 0; i < 3; i++) {
            long long int curMX = LLONG_MIN;
            for (int j = 0; j < n; j++) {
                if (used[j] == true)
                    continue;
                globalMX = max(globalMX, 1LL * nums[j]);
                curMX = max(curMX, 1LL * nums[j]);
            }

            if (curMX == LLONG_MIN)
                return globalMX;
            mx = curMX;

            for (int j = 0; j < n; j++)
                if (nums[j] == mx)
                    used[j] = true;
        }

        return mx;
    }
};