#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int MAX_N = 5555;
vector<int> g[MAX_N];
int tt, dfn[MAX_N], low[MAX_N];
int bcc;
int belong[MAX_N];
stack<int> s;
bool seen[MAX_N][MAX_N];
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;
    s.push(u);
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)
            continue;
        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        bcc++;
        while (1) {
            int v = s.top();
            s.pop();
            belong[v] = bcc;
            if (v == u)
                break;
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // memset(seen, 0, sizeof(seen)); // memset will cause MLE
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (seen[u][v])
            continue;
        seen[u][v] = seen[v][u] = true;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(belong, 0, sizeof(belong));
    bcc = 0;
    tt = 0;
    for (int i = 1; i <= n; i++)
        if (dfn[i] == -1) {
            dfs(i, -1);
        }
    int degree[MAX_N];
    memset(degree, 0, sizeof(degree));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            int v = g[i][j];
            if (belong[i] != belong[v]) {
                degree[belong[v]]++;
                degree[belong[i]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 2)
            ans++;
    }
    printf("%d\n", (ans + 1) / 2);
    return 0;
}
