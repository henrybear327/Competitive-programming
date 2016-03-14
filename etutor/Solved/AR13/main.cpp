#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int s, t;
int g[20][20];

bool visited[20];

bool dfs(int curr, int step)
{
    if (curr == t) {
        if (step == m)
            return true;
        return false;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && g[curr][i] == 1) {
            /*
            problem statement didn't say undirected graph!! so g[i][curr] !=
            g[curr][i]
            */

            visited[i] = true;
            if (dfs(i, step + 1) == true)
                return true;
            visited[i] = false;
        }
    }

    return false;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int tmp;
                scanf("%d", &tmp);

                g[i][j] = tmp;
            }
        }

        scanf("%d %d", &s, &t);

        fill(visited, visited + 20, false);
        visited[s] = true; // crucial!!
        printf("%s\n", dfs(s, 0) ? "Yes" : "No");
    }

    return 0;
}
