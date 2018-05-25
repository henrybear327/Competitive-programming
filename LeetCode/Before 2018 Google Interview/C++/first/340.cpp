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
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int ans = 0;

        int l = 0;
        unordered_map<char, int> cnt;
        for (int r = 0; r < (int)s.length(); r++) { //[l, r]
            cnt[s[r]]++;
            while (l < r && (int)cnt.size() > k) {
                cnt[s[l]]--;
                if (cnt[s[l]] == 0)
                    cnt.erase(s[l]);
                l++;
            }

            if ((int)cnt.size() <= k) {
                ans = max(ans, r - l + 1);
            }
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