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

// handle special cases first
// [], "", ...
class Solution
{
public:
    // https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
    /*
    - goal: find the furthest taller edge the current left edge can reach
    - key: a further but slightly taller edge is better than a huge tall edge that
    is closer
    - solution: Two-pointers.
    Walking from each end, guarantees the shorter edge meets its rightmost taller
    edge (which compensates for it's shortness since we are taking min)
    */
    // observation of two pointer
    // min(a,b) * distance
    // let old = min(a, b)
    // when we have distance - 1, but old inc by 1
    // we will have more than old value increment
    // e.g. min(2,3) * 4 = 2 * 4 = 8
    // d-- means 2 * 3 = 6 loses 2
    // but if min(3,3) = 3, 3 * 4 = 12 > what we lost!
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int l = 0, r = (int)height.size() - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r]) // find rightmost taller one
                l++;
            else
                r--;
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