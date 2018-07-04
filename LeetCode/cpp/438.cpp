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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> cnt(26, 0);
        for (auto i : p)
            cnt[i - 'a']++;

        vector<int> cand(26, 0);
        for (int i = 0; i < (int)p.length(); i++)
            cand[s[i] - 'a']++;

        vector<int> ans;
        if (cnt == cand)
            ans.push_back(0);
        for (int i = (int)p.length(); i < (int)s.length(); i++) {
            cand[s[i] - 'a']++;
            cand[s[i - p.length()] - 'a']--;

            if (cnt == cand)
                ans.push_back(i - p.length() + 1);
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
