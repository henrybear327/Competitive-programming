#include <cstdio>
#include <cstring>

int map[20][20];
int visited[20];
int ans[20];
int start, end;

int n, idx;
void dfs(int curr)
{
    if (n == idx && curr == end) {
        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (i != curr && visited[i] == 0 && map[curr][i] == 1) {
            visited[i] = 1;
            ans[idx++] = i;
            dfs(i);
            visited[i] = 0;
            idx--;
        }
    }
}

int main()
{
    while (scanf("%d", &n) == 1) {
        idx = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        memset(ans, 0, sizeof(ans));

        for (int i = 1; i <= n; i++) {
            int tmp;
            while (scanf("%d", &tmp) == 1 && tmp != 0) {
                map[tmp][i] = map[i][tmp] = 1;
            }
        }

        scanf("%d %d", &start, &end);
        ans[idx++] = start;
        visited[start] = 1;
        dfs(start);
    }

    return 0;
}
