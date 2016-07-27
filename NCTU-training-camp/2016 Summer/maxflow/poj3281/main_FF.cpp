#include <cstdio>
#include <cstring>

using namespace std;

#define N 444
int g[N][N];

void addEdge(int u, int v, int cap)
{
    g[u][v] = cap;
}

int maxN;
bool seen[N];
bool dfs(int u, int t)
{
    if (u == t)
        return true;

    seen[u] = true;

    for (int i = 0; i < maxN; i++) {
        if (g[u][i] >= 1 && seen[i] == false) {
            if (dfs(i, t) == true) {
                g[u][i]--;
                g[i][u]++;
                return true;
            }
        }
    }

    return false;
}

int maxFlow(int s, int t)
{
    int res = 0;

    memset(seen, false, sizeof(seen));
    while (dfs(s, t) == true) {
        res++;
        memset(seen, false, sizeof(seen));
    }

    return res;
}

int main()
{
    int n, f, d;
    while (scanf("%d %d %d", &n, &f, &d) == 3) {
        memset(g, 0, sizeof(g));
        maxN = f + 2 * n + d + 2;

        // build graph
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            for (int j = 0; j < a; j++) {
                // food to cow
                int food;
                scanf("%d", &food);

                addEdge(food, f + i + 1, 1);
            }

            for (int j = 0; j < b; j++) {
                // drink to cow
                int drink;
                scanf("%d", &drink);

                addEdge(f + n + i + 1, f + 2 * n + drink, 1);
            }

            // cow to cow
            addEdge(f + i + 1, f + n + i + 1, 1);
        }

        for (int i = 1; i <= f; i++) {
            // source to food
            addEdge(0, i, 1);
        }

        for (int i = 1; i <= d; i++) {
            // drink to sink
            addEdge(f + 2 * n + i, f + 2 * n + d + 1, 1);
        }

        /*
        for(int i = 0; i < maxN; i++)
            for(int j = 0; j < maxN; j++)
                printf("%d%c", g[i][j], j == maxN - 1 ? '\n' : ' ');
        */

        // get answer
        printf("%d\n", maxFlow(0, f + 2 * n + d + 1));
    }

    return 0;
}
