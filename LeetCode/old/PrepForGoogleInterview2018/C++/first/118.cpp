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

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows <= 0)
            return ans;

        vector<int> cur({1});
        ans.push_back(cur);
        for (int i = 1; i < numRows; i++) {
            cur.clear();

            cur.push_back(ans[i - 1].front());
            for (int j = 0; j + 1 < (int)ans[i - 1].size(); j++)
                cur.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            cur.push_back(ans[i - 1].back());

            ans.push_back(cur);
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