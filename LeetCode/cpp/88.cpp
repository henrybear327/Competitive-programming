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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // large->small, const space
        int i = m - 1, j = n - 1, idx = m + n - 1;
        while (i >= 0 || j >= 0) {
            int v1 = (i >= 0 ? nums1[i] : INT_MIN);
            int v2 = (j >= 0 ? nums2[j] : INT_MIN);

            nums1[idx--] = max(v1, v2);
            if (v1 > v2)
                i--;
            else
                j--;
        }

        // small -> large, extra space
        // int i = 0, j = 0;
        // vector<int> tmp(n + m);
        // while (i < m || j < n) {
        //     int v1 = (i < m ? nums1[i] : INT_MAX);
        //     int v2 = (j < n ? nums2[j] : INT_MAX);

        //     tmp[i + j] = min(v1, v2);
        //     if (v1 < v2)
        //         i++;
        //     else
        //         j++;
        // }

        // nums1 = tmp;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif