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

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return b.first < a.first;
}

class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        sort(people.begin(), people.end(), cmp);

        vector<pair<int, int>> ans;
        for (int i = 0; i < (int)people.size(); i++) {
            ans.insert(ans.begin() + people[i].second, people[i]);
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