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
private:
    inline int convert(int idx, int offset, int sz)
    {
        if (offset == -1)
            return idx;
        return (idx + offset) % sz;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int offset = -1;
        int sz = nums.size();
        if (sz == 0)
            return -1;

        for (int i = 1; i < sz; i++)
            if (nums[i - 1] > nums[i]) {
                offset = i;
                break;
            }

        int l = 0, r = sz; // searching on the "sorted array"
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int conversion = convert(mid, offset, sz); // convert back to the reality!
            // printf("%d %d %d %d\n", l, mid, r, conversion);

            if (nums[conversion] == target)
                return conversion;
            else if (nums[conversion] < target)
                l = mid;
            else
                r = mid;
        }

        l = convert(l, offset, sz);
        return nums[l] == target ? l : -1;
    }
};

#ifdef LOCAL
int main()
{
    vector<int> inp({3, 5, 1});
    int target = 5;
    printf("ans = %d\n", Solution().search(inp, target));
    return 0;
}
#endif