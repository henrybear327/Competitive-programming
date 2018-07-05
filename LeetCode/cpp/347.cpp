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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        for (auto i : nums)
            cnt[i]++;
        vector<pair<int, int>> ans;
        for (auto i : cnt)
            ans.push_back(make_pair(i.second, i.first));
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());

        vector<int> ret;
        for (int i = 0; i < k; i++)
            ret.push_back(ans[i].second);
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
