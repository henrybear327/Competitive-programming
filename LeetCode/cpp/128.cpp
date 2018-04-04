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
    // (expected O(n))
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto i : nums)
            s.insert(i);

        auto it = s.begin();
        int ans = 0;
        while (it != s.end()) {
            int val = *it;
            s.erase(it);
            int cnt = 1;
            // inc
            for (int i = 1;; i++) {
                if (s.find(val + i) != s.end()) {
                    cnt++;
                    s.erase(val + i);
                } else {
                    break;
                }
            }
            // dec
            for (int i = 1;; i++) {
                if (s.find(val - i) != s.end()) {
                    cnt++;
                    s.erase(val - i);
                } else {
                    break;
                }
            }

            ans = max(ans, cnt);
            it = s.begin();
        }

        return ans;
    }
    // O(nlogn)
    // int longestConsecutive(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //         return 0;

    //     sort(nums.begin(), nums.end());
    //     {
    //         auto it = unique(nums.begin(), nums.end());
    //         nums.resize(distance(nums.begin(), it));
    //     }

    //     int ans = 1, cnt = 1;
    //     for (int i = 1; i < (int)nums.size(); i++) {
    //         if (nums[i] - 1 != nums[i - 1]) {
    //             ans = max(ans, cnt);
    //             cnt = 1;
    //         } else {
    //             cnt++;
    //         }
    //     }
    //     ans = max(ans, cnt);
    //     return ans;
    // }
};

#ifdef LOCAL
int main()
{
    vector<int> inp({100, 4, 200, 1, 3, 2});
    cout << Solution().longestConsecutive(inp) << endl;
    return 0;
}
#endif