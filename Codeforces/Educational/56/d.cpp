#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int N = 300010;
const ll mod = 998244353;
vector<int> g[N];
bool seen[N];
int color[N];
bool error;
int type1 = 0, type2 = 0;

void dfs(int u, int c)
{
    // cout << "u " << u << endl;
    if (seen[u])
        return;
    seen[u] = true;
    color[u] = c;

    if (c == 0)
        type1++;
    else
        type2++;

    for (auto v : g[u]) {
        if (error)
            return;

        if (seen[v] == false)
            dfs(v, c == 0 ? 1 : 0);
        else {
            if (color[v] == color[u]) {
                error = true;
                return;
            }
        }
    }
}

ll p22[N];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        g[i].clear();
    // memset(seen, false, sizeof(seen));
    // memset(color, 0, sizeof(color));
    for (int i = 0; i < n; i++) {
        seen[i] = false;
        color[i] = 0;
    }

    error = false;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 1;

    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            // cout << "i " << i << endl;
            error = false;
            type1 = 0;
            type2 = 0;
            dfs(i, 0);

            if (error)
                break;

            // cout << type1 << " " << type2 << endl;
            ans = (p22[type1] + p22[type2]) * ans % mod;
            // cout << "ans 2"
            //   << " " << ans << endl;
        }
    }

    if (error)
        printf("0\n");
    else
        printf("%lld\n", ans);
}

int main()
{
    p22[0] = 1;
    for (int i = 1; i < N; i++)
        p22[i] = p22[i - 1] * 2 % mod;

    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
