#include <bits/stdc++.h>

using namespace std;

vector<int> g[444];
int n, m;
int num[22][22];
bool seen[22][22];
typedef pair<int, int> ii;
vector<ii> path;
bool ok;
void dfs(int x, int y)
{
    // printf("%d %d\n", x, y);

    if ((int)path.size() == n * m) {
        // sol
        /*
                printf("=====\n");
        for (auto i : path)
            printf("(%d %d) ", i.first, i.second);
        printf("\n");
        printf("=====\n");
                */
        ok = true;
        return;
    }

    seen[x][y] = true;

    for (auto i : g[num[x][y]]) {
        int xx = i / m;
        int yy = i % m;

        if (seen[xx][yy])
            continue;
        path.push_back({xx, yy});
        dfs(xx, yy);
        if (ok == true)
            return;
        path.pop_back();
    }

    seen[x][y] = false;
}

void solve()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n * m; i++) {
        g[i].clear();
    }

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            num[i][j] = idx++;

    // build graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            set<int> cand;
            for (int k = 0; k < idx; k++)
                cand.insert(k);

            // col
            for (int k = 0; k < n; k++)
                cand.erase(num[k][j]);
            // row
            for (int k = 0; k < m; k++)
                cand.erase(num[i][k]);
            // diag
            for (int k = 0; k < max(n, m); k++) {
                if (i + k < n && j + k < m)
                    cand.erase(num[i + k][j + k]);
                if (i + k < n && j - k >= 0)
                    cand.erase(num[i + k][j - k]);
                if (i - k >= 0 && j + k < m)
                    cand.erase(num[i - k][j + k]);
                if (i - k >= 0 && j - k >= 0)
                    cand.erase(num[i - k][j - k]);
            }

            // build graph
            for (auto k : cand)
                g[num[i][j]].push_back(k);
        }
    }

    /*
    for (int i = 0; i < idx; i++) {
    printf("%d: ", i);
    for (auto j : g[i])
        printf("%d ", j);
    printf("\n");
    }
    */

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            ok = false;
            memset(seen, false, sizeof(seen));
            // printf("start %d %d\n", i, j);
            path.clear();
            path.push_back({i, j});
            dfs(i, j);
            if (ok) {
                printf("POSSIBLE\n");
                for (auto k : path)
                    printf("%d %d\n", k.first + 1, k.second + 1);
                goto done;
            }
            path.clear();
        }

done:
    if (ok == false)
        printf("IMPOSSIBLE\n");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
