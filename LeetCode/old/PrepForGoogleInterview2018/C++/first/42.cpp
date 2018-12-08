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
    // O(N^2)
    // int trap(vector<int> &height)
    // {
    //     // brute force: for every position, ...
    //     int sz = height.size();
    //     if (sz == 0)
    //         return 0;
    //     int ans = 0;
    //     for (int i = 1; i < sz - 1; i++) {
    //         int l = INT_MIN, r = INT_MIN;
    //         for (int j = 0; j < i; j++)
    //             l = max(l, height[j]);
    //         for (int j = i + 1; j < sz; j++)
    //             r = max(r, height[j]);
    //         int diff = min(l, r) - height[i];
    //         if (diff > 0)
    //             ans += diff;
    //     }

    //     return ans;
    // }

    // O(N)
    int trap(vector<int> &height)
    {
        // brute force: for every position, ...
        // l/r max can be precomputed
        int sz = height.size();
        if (sz == 0)
            return 0;
        int ans = 0;
        int lmx[sz], rmx[sz];
        memset(lmx, 0, sizeof(lmx));
        lmx[0] = height[0];
        memset(rmx, 0, sizeof(rmx));
        rmx[sz - 1] = height[sz - 1];
        for (int i = 1; i < sz; i++)
            lmx[i] = max(lmx[i - 1], height[i]);
        for (int i = sz - 2; i >= 0; i--)
            rmx[i] = max(rmx[i + 1], height[i]);

        for (int i = 1; i < sz - 1; i++) {
            int diff = min(lmx[i], rmx[i]) - height[i];
            if (diff > 0)
                ans += diff;
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif