#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // two pointers

        int l = 0;
        unordered_map<char, int> cnt;
        int ans = 0;
        for (int r = 0; r < (int)s.length(); r++) {
            cnt[s[r]]++;

            if (cnt[s[r]] > 1) {
                while (l <= r && cnt[s[r]] > 1) {
                    cnt[s[l]]--;
                    l++;
                }
            }

            ans = max(ans, r - l + 1);
        }

        // no need to check afterwards since the answer will only be shorter

        return ans;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution ss;
    printf("%d\n", ss.lengthOfLongestSubstring(s));
    return 0;
}