#include <cstdio>
#include <cstring>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int people, query;
int graph[4100][4100];
bool visited[4100];

int origin;
#define INT_MAX 100000000
int ans = INT_MAX;

int count[4100];
void dfs(int start, int step)
{
    // printf("%d %d\n", start, step);
    if (step == 3) {
        bool find = false;

        for (int i = 0; i < count[start]; i++) {
            if (graph[start][i] == origin) {
                find = true;
                break;
            }
        }

        if (find == false)
            return;

        /*
        printf("visited\n");
        for (int i = 1; i <= people; i++)
            printf("%d ", visited[i]);
        printf("\n");
        */

        int cnt = 0;
        for (int i = 1; i <= people; i++) {
            if (visited[i] == true) {
                cnt += (count[i] - 2);
            }
        }
        // printf("%d\n", cnt);

        ans = MIN(ans, cnt);
        return;
    }

    for (int i = 0; i < count[start]; i++) {
        if (graph[start][i] > 0 && visited[graph[start][i]] == false) {
            visited[graph[start][i]] = true;
            dfs(graph[start][i], step + 1);
            visited[graph[start][i]] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &people, &query);

    memset(graph, false, sizeof(graph));
    memset(count, 0, sizeof(count));

    for (int i = 0; i < query; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a][count[a]] = b;
        graph[b][count[b]] = a;
        count[a]++;
        count[b]++;
    }

    /*
    printf("count\n");
    for (int i = 1; i <= people; i++)
        printf("%d ", count[i]);
    printf("\n");
    */

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= people; i++) {
        origin = i;
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    if (ans != INT_MAX)
        printf("%d\n", ans);
    else
        printf("-1\n");

    return 0;
}
