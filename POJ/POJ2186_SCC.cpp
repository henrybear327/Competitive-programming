#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 11111;
vector<int> g[MAX_N];

int tt = 0, dfn[MAX_N], low[MAX_N];
stack<int> s;
int belong[MAX_N];
bool in_stack[MAX_N];
int scc = 0;

void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;
    s.push(u);
    in_stack[u] = true;

    for (int i = 0; i < (int)g[u].size(); i++) {
        const int &v = g[u][i];

        // if(v == p) // wrong condition, sample input can reveal this error
        // continue;

        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if (in_stack[v])
                low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        scc++;
        while (1) {
            int v = s.top();
            s.pop();
            belong[v] = scc;
            in_stack[v] = false;

            if (u == v)
                break;
        }
    }
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++)
            g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;

            g[u].push_back(v);
        }

        tt = 0;
        scc = 0;
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        memset(belong, 0, sizeof(belong));
        memset(in_stack, false, sizeof(in_stack));
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }

        int inDeg[scc + 1], outDeg[scc + 1];
        memset(inDeg, 0, sizeof(inDeg));
        memset(outDeg, 0, sizeof(outDeg));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)g[i].size(); j++) {
                int u = i;
                int v = g[i][j];

                if (belong[u] != belong[v]) {
                    inDeg[belong[v]]++;
                    outDeg[belong[u]]++;
                }
            }
        }

        int cnt_no_out = 0, who;
        for (int i = 1; i <= scc; i++) { // 注意 scc 區間，別被弄混了
            if (outDeg[i] == 0) {
                cnt_no_out++;
                who = i;
            }
        }

        if (cnt_no_out != 1)
            printf("0\n");
        else {
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (belong[i] == who)
                    ans++;
            printf("%d\n", ans);
        }
    }

    return 0;
}
