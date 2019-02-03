#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

set<int> g[44];
int n, m;

void off(ll &mask, int who)
{
    mask &= ~(1LL << who);
}

void on(ll &mask, int who)
{
    mask |= (1LL << who);
}

int mx;
int dp[1 << 20];
int dfs(int u, ll mask,
        int ans) // return int: the best value with the currently used vertices
{
#ifdef DEBUG
    printf("%d %lld %d\n", u, mask, ans);
#endif
    if (u == m) {
        mx = max(mx, ans);
        return ans;
    }

    int right = mask >> ((m + 1) / 2);
    if (u == m / 2 + 1 && dp[right] != -1) {
        // printf("dp return %d %d %d\n", right, dp[right], ans);
        mx = max(mx, dp[right] + ans);
        return dp[right] + ans;
    }

    int ret;
    if (((mask >> u) & 1) == 0)
        ret = dfs(u + 1, mask, ans);
    else {
        // pick
        // set self + connected bits to off
        ll orig = mask;
        off(mask, u);
        for (auto v : g[u])
            off(mask, v);
        int ret1 = dfs(u + 1, mask, ans + 1);
        mask = orig;

        // don't pick
        int ret2 = dfs(u + 1, mask, ans);

        ret = max(ret1, ret2);
    }

    if (u == m / 2 + 1) {
        // printf("dp write %d %d %d\n", right, ans, ret);
        // we should only keep the ones generated from the right, not all
        dp[right] = max(dp[right], ret - ans);
    }

    return ret;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));

    int idx = 0;
    unordered_map<string, int> nameMapping;
    set<int> collection;
    for (int i = 0; i <= n; i++) {
        int command;
        char name[44];
        if (i < n)
            scanf("%d", &command);
        if (i == n || command == 1) {
            for (auto u : collection)
                for (auto v : collection)
                    if (u != v)
                        g[u].insert(v), g[v].insert(u); /*printf("%d - %d\n", u, v)*/
            collection.clear();
        } else {
            scanf("%s", name);
            if (nameMapping.find(name) == nameMapping.end())
                nameMapping[name] = idx++;

            int id = nameMapping[name];
            collection.insert(id);
        }
    }

    ll mask = (1LL << m) - 1;
    dp[0] = 0;
    mx = 0;
    dfs(0, mask, 0);

    printf("%d\n", mx);

    return 0;
}
