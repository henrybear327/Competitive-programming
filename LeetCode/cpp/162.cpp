#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    // int findPeakElement(vector<int> &nums)
    // {
    //     long long int mx = LLONG_MIN;
    //     int idx = -1;
    //     for (int i = 0; i < (int)nums.size(); i++)
    //         if (nums[i] > mx) {
    //             mx = nums[i];
    //             idx = i;
    //         }
    //     return idx;
    // }

    int findPeakElement(vector<int> &nums)
    {
        int n = (int)nums.size(), l = 0, r = n - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[mid + 1])
                l = mid;
            else
                r = mid;
        }

        return nums[r] > nums[l] ? r : l;
    }

    // int findPeakElement(vector<int> &nums)
    // {
    //     int l = 0, r = (int)nums.size();
    //     while (r - l > 1) {
    //         int mid = l + (r - l) / 2;

    //         long long int a, b;
    //         if (mid >= 0)
    //             a = nums[mid];
    //         else
    //             a = LLONG_MIN;
    //         if (mid + 1 < (int)nums.size())
    //             b = nums[mid + 1];
    //         else
    //             b = LLONG_MIN;

    //         if (a < b)
    //             l = mid;
    //         else
    //             r = mid;
    //     }

    //     return r == (int)nums.size() ? l : (nums[l] > nums[r] ? l : r);
    // }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif