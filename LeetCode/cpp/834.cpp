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
    void dfs(int u, int par, vector<vector<int>> &g,
             vector<int> &subtreeNodeCount, vector<int> &subtreeSum, int n,
             bool isSecondPass = false)
    {
        if (isSecondPass == false)
            subtreeNodeCount[u]++;

        if (isSecondPass && par != -1) {
            // clean up info of current subtree from parent's answer
            int parSubtreeSum = subtreeSum[par] - subtreeSum[u] - subtreeNodeCount[u];
            subtreeSum[u] = parSubtreeSum + (n - subtreeNodeCount[u]) + subtreeSum[u];
        }

        for (auto v : g[u]) {
            if (v == par)
                continue;
            dfs(v, u, g, subtreeNodeCount, subtreeSum, n, isSecondPass);
            if (isSecondPass == false) {
                subtreeNodeCount[u] += subtreeNodeCount[v];
                subtreeSum[u] += subtreeNodeCount[v] + subtreeSum[v];
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<int> subtreeNodeCount(N, 0), subtreeSum(N, 0);

        vector<vector<int>> g(N, vector<int>());
        for (auto edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, g, subtreeNodeCount, subtreeSum, N);
        dfs(0, -1, g, subtreeNodeCount, subtreeSum, N, true);

        return subtreeSum;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif