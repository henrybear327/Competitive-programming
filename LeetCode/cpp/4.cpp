#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int sz = nums1.size() + nums2.size();
        if (sz == 0)
            return 0.0;

        vector<int> ans(sz);
        for (unsigned int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
            int v1 = INT_MAX, v2 = INT_MAX;
            if (i < nums1.size())
                v1 = nums1[i];
            if (j < nums2.size())
                v2 = nums2[j];

            ans[i + j] = (v1 < v2 ? v1 : v2);
            if (v1 < v2)
                i++;
            else
                j++;
        }

        if (sz % 2 == 1) {
            return ans[sz / 2];
        } else {
            return (double)(ans[sz / 2] + ans[sz / 2 - 1]) / 2;
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif