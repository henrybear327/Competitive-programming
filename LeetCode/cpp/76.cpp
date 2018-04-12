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
private:
    bool check(map<char, int> &s_cnt, map<char, int> &t_cnt)
    {
        bool ok = true;
        for (auto i : t_cnt)
            if (s_cnt.count(i.first) == 0 || s_cnt[i.first] < i.second)
                ok = false;
        return ok;
    }

public:
    string minWindow(string s, string t)
    {
        map<char, int> t_cnt;
        for (auto i : t)
            t_cnt[i]++;

        map<char, int> s_cnt;
        int l = 0;
        string ans = s + s;
        for (int r = 0; r < (int)s.length(); r++) { // [l, r]
            s_cnt[s[r]]++;
            while (l < r && s_cnt.size() >= t_cnt.size()) {
                // only remove when l is not in t_cnt
                if (t_cnt.count(s[l]) == 0 || s_cnt[s[l]] > t_cnt[s[l]]) {
                    s_cnt[s[l]]--;
                    if (s_cnt[s[l]] == 0)
                        s_cnt.erase(s[l]);

                    l++;
                } else {
                    break;
                }
            }

            if (s_cnt.size() >= t_cnt.size() && (int)ans.length() > r - l + 1) {
                if (check(s_cnt, t_cnt))
                    ans = s.substr(l, r - l + 1);
            }
        }

        return ans == s + s ? "" : ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
