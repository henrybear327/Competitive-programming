#include <cstdio>

#define INT_MAX 100000

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int cases;
    scanf("%d", &cases);

    int count = 1;
    while (cases--) {
        int building, road;
        scanf("%d %d", &building, &road);

        int graph[building][building];
        for (int i = 0; i < building; i++) {
            for (int j = 0; j < building; j++)
                graph[i][j] = INT_MAX;
            graph[i][i] = 0;
        }

        for (int i = 0; i < road; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        int start, end;
        scanf("%d %d", &start, &end);

        for (int k = 0; k < building; k++)
            for (int i = 0; i < building; i++)
                for (int j = 0; j < building; j++)
                    graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);

        int ans = -1;
        for (int i = 0; i < building; i++)
            if (graph[start][i] != INT_MAX && graph[end][i] != INT_MAX)
                ans = MAX(ans, graph[start][i] + graph[end][i]);

        printf("Case %d: %d\n", count++, ans);
    }

    return 0;
}
