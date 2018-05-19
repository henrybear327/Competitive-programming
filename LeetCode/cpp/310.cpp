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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> g(n, vector<int>());

        vector<int> in(n, 0), level(n, 0);
        for (auto i : edges) {
            in[i.first]++;
            g[i.first].push_back(i.second);
            in[i.second]++;
            g[i.second].push_back(i.first);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (in[i] == 1)
                q.push(i);

        int mx = 0;
        while (q.size() > 0) {
            int u = q.front();
            q.pop();

            for (auto v : g[u]) {
                in[v]--;
                if (in[v] == 1) {
                    level[v] = level[u] + 1;
                    mx = max(mx, level[v]);
                    q.push(v);
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (level[i] == mx)
                ans.push_back(i);
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