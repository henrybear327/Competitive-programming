#include <bits/stdc++.h>

using namespace std;

#define N 100010
vector<int> g[N];
int deg[N];
bool seen[N];

vector<int> group;
void dfs(int u)
{
    if (seen[u] == true)
        return;
    seen[u] = true;
    group.push_back(u);

    for (auto i : g[u])
        dfs(i);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        printf("2\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        g[i].clear();
        deg[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            // find all nodes in the subtree
            group.clear();
            dfs(i);

            // add leaf to queue
            queue<int> q;
            for (auto v : group) {
                if (deg[v] == 1) {
                    q.push(v);
                }
            }

            // find tree center / radius
            int radius = 0;
            int level[100010] = {0};
            while (q.empty() == false) {
                int cur = q.front();
                q.pop();

                for (auto v : g[cur]) {
                    deg[v]--;
                    if (deg[v] == 1) {
                        level[v] = level[cur] + 1;
                        radius = max(radius, level[v]);
                        q.push(v);
                    }
                }
            }

            int cntCenter = 0;
            for (int u : group)
                if (level[u] == radius)
                    cntCenter++;
            ans.push_back(2 * radius + cntCenter - 1);
        }
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    int mx = ans[0];
    if (ans.size() > 1)
        mx = max(mx, (ans[0] + 1) / 2 + (ans[1] + 1) / 2 + 1);
    if (ans.size() > 2)
        mx = max(mx, (ans[1] + 1) / 2 + (ans[2] + 1) / 2 + 2);
    printf("%d\n", mx);

    return 0;
}
