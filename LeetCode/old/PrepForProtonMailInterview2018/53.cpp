// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
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
    int maxSubArray(vector<int> &nums)
    {
        int mxSoFar = INT_MIN;
        int ending = 0;
        for (auto i : nums) {
            ending = max(ending + i, i);
            mxSoFar = max(mxSoFar, ending);
        }

        return mxSoFar;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
