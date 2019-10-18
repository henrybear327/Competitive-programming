class Solution
{
private:
    vector<int> sum;
    bool dfs(int depth, int arr[], const vector<int> &nums, int k, int target)
    {
        if (depth == (int)nums.size()) {
            /*
            for (int i = 0; i < nums.size(); i++) {
                printf("%d %d\n", i, arr[i]);
            }
            */
            return true;
        }

        for (int i = 0; i < k; i++) {
            arr[depth] = i;
            sum[i] += nums[depth];

            if (sum[i] > target) {
                // skip
            } else {
                if (dfs(depth + 1, arr, nums, k, target))
                    return true;
            }

            sum[i] -= nums[depth];
            arr[depth] = -1;

            // we guarantee the sum[i] = 0 will be consecutive, and towards the end
            // only!
            if (sum[i] == 0) // WTF?
                break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int tot = 0;
        for (auto i : nums)
            tot += i;
        if (tot % k != 0)
            return false;

        int target = tot / k;
        int arr[nums.size()];
        sum = vector<int>(k, 0);

        for (auto i : nums)
            if (i > target)
                return false;

        return dfs(0, arr, nums, k, target);
    }
};
