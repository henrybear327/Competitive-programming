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

// [28,54,7,-70,22,65,-6]
// 100
// formation: [(this is over k), -x] = k
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int pre = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int ans = 0;
        for (auto i : nums) {
            pre += i;

            // i - x = k
            // x = i - k
            ans += cnt[pre - k];
            cnt[pre]++;
        }

        return ans;
    }

    int subarraySum_WA(vector<int> &nums, int k)
    {
        int l = 0, sum = 0, n = (int)nums.size();
        int ans = 0;
        for (int r = 0; r < n; r++) { // [l, r)
            sum += nums[r];
            if (sum == k)
                ans++;

            while (l < r && sum > k) {
                sum -= nums[l];
                l++;

                if (sum == k)
                    ans++;
            }
            // cout << sum << endl;
        }

        // cout << ans << endl;
        while (l < n - 1) {
            sum -= nums[l];
            l++;

            if (sum == k)
                ans++;
            // cout << ans << " " << sum << endl;
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