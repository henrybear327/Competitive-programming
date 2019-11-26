#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<ii>> g;
vector<int> ans;
int mx = 0;
void dfs(int u, int p, int usedColor)
{
    int idx = 1;
    for (auto cur : g[u]) {
        int v = cur.first;
        int edgeNumber = cur.second;
        if (v == p) // skip parent
            continue;
        if (p == -1) {
            ans[edgeNumber] = idx;
            mx = max(mx, idx);
            dfs(v, u, idx);
            idx++;
        } else {
            if (usedColor == idx)
                idx++;
            mx = max(mx, idx);
            ans[edgeNumber] = idx;
            dfs(v, u, idx);
            idx++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    g = vector<vector<ii>>(n, vector<ii>());
    ans = vector<int>(n - 1, -1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(ii(v, i));
        g[v].push_back(ii(u, i));
    }

    dfs(0, -1, -1);

    printf("%d\n", mx);
    for (int i = 0; i < n - 1; i++)
        printf("%d\n", ans[i]);

    return 0;
}
