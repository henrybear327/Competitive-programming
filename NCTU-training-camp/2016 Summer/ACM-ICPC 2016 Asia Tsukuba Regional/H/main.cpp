#include <bits/stdc++.h>

using namespace std;

#define N 111
int g[N][N];
int used[N][N];
int gift[N];
bool seen[N];
int n, m;

int check;
void convertToDirected(int u)
{
    seen[u] = true;

    for (int v = 0; v < n; v++) {
        if (g[u][v] == 1) {
            if (used[v][u] == 1 || used[u][v] == 1)
                continue;

            used[u][v] = 1;
            gift[v]++;
            check++;

            if (seen[v] == false)
                convertToDirected(v);
        }
    }
}

typedef pair<int, int> ii;

ii findMax(int u)
{
    ii res = ii(u, gift[u]); // point, val
    seen[u] = true;
    for (int v = 0; v < n; v++) {
        if (used[u][v] == 1 && seen[v] == false) {
            ii tmp = findMax(v);
            if (res.second <= tmp.second) {
                res = tmp;
            }
        }
    }
    return res;
}

bool changeDirection(int u, int target)
{
    if (u == target) {
        seen[u] = true;
        return true;
    }

    seen[u] = true;
    for (int v = 0; v < n; v++) {
        if (used[u][v] == 1 && seen[v] == false) {
            if (changeDirection(v, target)) {
                used[u][v] = 0;
                used[v][u] = 1;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        memset(g, 0, sizeof(g));
        memset(used, 0, sizeof(used));

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;
            g[u][v] = 1;
            g[v][u] = 1;
        }

        memset(seen, false, sizeof(seen));
        memset(gift, 0, sizeof(gift));

        check = 0;

        for (int i = 0; i < n; i++) {
            if (seen[i] == false)
                convertToDirected(i);
        }
        assert(check == m);

        /*
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                printf("%d ", used[i][j]);
            printf("\n");
        }
        printf("\n");
        */

        bool hasChange = true;
        while (hasChange == true) {
            hasChange = false;
            for (int i = 0; i < n; i++) {
                memset(seen, false, sizeof(seen));
                ii mx = findMax(i);
                // printf("%d %d %d\n", i, mx.first, mx.second); // node, value

                if (gift[i] > mx.second)
                    continue;

                if (abs(mx.second - gift[i]) <= 1)
                    continue;
                else
                    hasChange = true;

                gift[i]++;
                gift[mx.first]--;
                memset(seen, false, sizeof(seen));
                changeDirection(i, mx.first);

                /*
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++)
                        printf("%d ", used[i][j]);
                    printf("\n");
                }
                printf("\n");
                */
            }
        }

        int mx = 0, mn = INT_MAX;
        int total = 0;
        for (int i = 0; i < n; i++) {
            // printf("%d: %d\n", i, gift[i]);
            total += gift[i];
            mx = max(mx, gift[i]);
            mn = min(mn, gift[i]);
        }

        assert(total == m);

        printf("%d %d\n", mn, mx);
    }

    return 0;
}
