class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int realLeft = -1, realRight = -1, n = nums.size();
        if (n == 0) // always do this first
            return -1;

        if (nums.front() <= nums.back()) { // sorted
            realLeft = 0;
            realRight = n - 1;
        } else {
            // find peak
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (nums[mid] > nums[mid + 1]) { // man this is crucial!
                    l = mid + 1;
                    break;
                }

                if (nums[l] <= nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            // cout << l - 1 << endl;
            realRight = l - 1;
            realLeft = realRight + 1;
        }

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int newMid = (mid + realLeft) % n;

            if (nums[newMid] < target) {
                l = mid + 1;
            } else if (nums[newMid] > target) {
                r = mid - 1;
            } else {
                return newMid;
            }
        }

        return -1;
    }
};
