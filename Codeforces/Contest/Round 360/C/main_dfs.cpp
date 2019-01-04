#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

#define N 100100
vector<int> g[N];

int seen[N];
bool dfs(int u)
{
    queue<int> q;
    for (auto v : g[u]) {
        if (seen[v] == -1) {
            seen[v] = (seen[u] ^ 1);
            q.push(v);
        } else {
            if (seen[v] == seen[u])
                return false;
        }
    }

    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        if (dfs(v) == false)
            return false;
    }

    return true;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    memset(seen, -1, sizeof(seen));

    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool check = true;
    for (int i = 1; i <= n; i++) {
        if (seen[i] == -1) {
            seen[i] = 0;
            check = dfs(i);
        }
        if (check == false)
            break;
    }

    if (check) {
        vector<int> ans[2];
        for (int i = 1; i <= n; i++) {
            if (seen[i] != -1) {
                ans[seen[i] % 2].push_back(i);
            }
        }

        printf("%d\n", (int)ans[0].size());
        for (int i = 0; i < (int)ans[0].size(); i++)
            printf("%d%c", ans[0][i], i == (int)ans[0].size() - 1 ? '\n' : ' ');
        printf("%d\n", (int)ans[1].size());
        for (int i = 0; i < (int)ans[1].size(); i++)
            printf("%d%c", ans[1][i], i == (int)ans[1].size() - 1 ? '\n' : ' ');
    } else {
        printf("-1\n");
    }

    return 0;
}
