class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // two pass
        int idx = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zero++;
            else
                nums[idx] = nums[i], idx++;
        }

        for (int i = 0; i < zero; i++)
            nums[idx++] = 0;
    }
};

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zero = n, nonZero = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zero = min(zero, i);
            else
                nonZero = min(nonZero, i);
        }

        while (zero < n && nonZero < n) {
            if (zero < nonZero) {
                swap(nums[nonZero], nums[zero]);
                while (nonZero < n && nums[nonZero] == 0)
                    nonZero++;
                while (zero < n && nums[zero] != 0)
                    zero++;
            } else {
                nonZero++;
                while (nonZero < n && nums[nonZero] == 0)
                    nonZero++;
            }
        }
    }
};
