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
// range of input?
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int left = n, right = -1;
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());

        for(int i = 0; i < n; i++) {
            if(ans[i] != nums[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        return left == n ? 0 : right - left + 1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
