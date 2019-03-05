class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        // 1 1 1 3
        // 1 2 2 2
        // 1 2 2
        int n = nums.size();
        return nums[n / 2];
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        srand(time(NULL));
        // expected O(n)
        int cnt = 0, idx = -1, n = nums.size();
        do {
            cnt = 0;
            idx = rand() % n;
            for (auto i : nums)
                if (nums[idx] == i)
                    cnt++;
        } while (cnt <= n / 2);

        return nums[idx];
    }
};
