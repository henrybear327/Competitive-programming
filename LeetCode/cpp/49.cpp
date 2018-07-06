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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> res;

        for (auto i : strs) {
            vector<int> cnt(26, 0);
            for (int j : i) {
                cnt[j - 'a']++;
            }
            res[cnt].push_back(i);
        }

        vector<vector<string>> ans;
        for (auto i : res)
            ans.push_back(i.second);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
