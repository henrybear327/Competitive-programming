#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

set<int> ans; // edge number

vector<ii> g[300010];
int n, k, d;
bool seen[300010];
void dfs(int u, int p, int step)
{
    // printf("u %d p %d step %d\n", u, p, step);

    seen[u] = true;
    if (step == d) {
        // printf("%d %d\n", u, step);

        /*
        for(auto v : g[u]) {
                if(v.first == p)
                        continue;
                // printf("delete %d\n", v.second);
                ans.insert(v.second);
        }
        */
        return;
    }

    for (auto v : g[u]) {
        if (v.first == p)
            continue;
        /*
        if(ans.find(v.second) != ans.end()) // in3 will tell you why... QQ
                continue;
        */
        if (seen[v.first]) {
            ans.insert(v.second);
            continue;
        }

        dfs(v.first, u, step + 1);
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &d);

    set<int> police;
    for (int i = 0; i < k; i++) {
        int pos;
        scanf("%d", &pos);
        police.insert(pos);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (police.find(u) != police.end() &&
            police.find(v) != police.end()) { // this edge is useless
            ans.insert(i + 1);
            continue;
        }

        // printf("u %d v %d\n", u, v);
        g[u].push_back(ii(v, i + 1));
        g[v].push_back(ii(u, i + 1));
    }

    memset(seen, false, sizeof(seen));
    for (auto u : police) {
        // printf("==u = %d===\n", u);
        dfs(u, -1, 0);
    }

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d ", i);

    return 0;
}
