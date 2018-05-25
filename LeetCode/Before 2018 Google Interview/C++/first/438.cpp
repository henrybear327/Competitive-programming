// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

// observation
// do the char count!
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int cnt[26] = {0};
        for (int i = 0; i < (int)p.length(); i++)
            cnt[p[i] - 'a']++;

        vector<int> ans;
        if (s.length() < p.length())
            return ans;

        int cnt1[26] = {0};
        for (int i = 0; i < (int)p.length() - 1; i++) {
            cnt1[s[i] - 'a']++;
        }

        for (int i = p.length() - 1; i < (int)s.length(); i++) {
            cnt1[s[i] - 'a']++;

            bool ok = true;
            for (int j = 0; j < 26; j++)
                if (cnt[j] != cnt1[j])
                    ok = false;
            if (ok)
                ans.push_back(i - p.length() + 1);

            cnt1[s[i - p.length() + 1] - 'a']--;
        }

        return ans;
    }
};

int main()
{
    return 0;
}