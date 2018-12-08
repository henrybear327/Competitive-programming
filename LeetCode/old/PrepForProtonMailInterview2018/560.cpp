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
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> pre;
        pre[0]++;
        int sum = 0, ans = 0;
        for (auto i : nums) {
            sum += i;

            int t = sum - k;
            ans += pre[t];
            
            /*
            [1]
            0
            */
            pre[sum]++; // this is crucial, self-self issue
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
