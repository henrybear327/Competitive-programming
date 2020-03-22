#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &inp, int n, int k, int rem, int cur, int tot,
         int &mx)
{
    if (cur == n) {
        if (rem == 0)
            mx = max(mx, tot);
        return;
    }

    if (rem > (n - cur) * k)
        return;

    for (int i = 0; i <= k; i++) {
        int val = (i > 0 ? inp[cur][i - 1] : 0);
        dfs(inp, n, k, rem - i, cur + 1, tot + val, mx);
    }
}

int solve()
{
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);

    vector<vector<int>> inp(n, vector<int>(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            scanf("%d", &inp[i][j]);
            if (j > 0)
                inp[i][j] = inp[i][j - 1] + inp[i][j];
        }

    int mx = 0;
    dfs(inp, n, k, p, 0, 0, mx);
    return mx;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case #%d: %d\n", i, solve());

    return 0;
}
