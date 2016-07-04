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
bool bfs(int start)
{
    queue<int> q[2];
    int r = 1;
    seen[start] = r;

    r++;
    for (int i : g[start]) {
        seen[i] = r;
        q[r % 2].push(i);
    }

    while (q[r % 2].empty() == false) {
        int cur = q[r % 2].front();
        q[r % 2].pop();

        for (int i : g[cur]) {
            if (seen[i] == -1) {
                q[(r + 1) % 2].push(i);
                seen[i] = r + 1;
            }
            if (seen[i] == seen[cur])
                return false;
        }

        if (q[r % 2].empty())
            r++;
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
    for (int i = 1; i <= n; i++) { // bitch....
        if (seen[i] == -1)
            check = bfs(i);
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
