#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int vertice_count;
bool adjacency_matrix[101][101], used[101];
void dfs(int vertex)
{
    for (int i = 1; i <= vertice_count; i++) {
        if (adjacency_matrix[vertex][i] == true && used[i] == false) {
            adjacency_matrix[vertex][i] = false;
            used[i] = true;
            // printf("here\n");
            dfs(i);
            adjacency_matrix[vertex][i] = true;
        }
    }

    return;
}

int main()
{
    while (scanf("%d", &vertice_count) == 1 && vertice_count != 0) {
        memset(adjacency_matrix, false, sizeof(adjacency_matrix));
        while (1) {
            int cur_vertex;
            scanf("%d", &cur_vertex);
            if (cur_vertex == 0)
                break;

            int temp;
            scanf("%d", &temp);
            while (temp != 0) {
                adjacency_matrix[cur_vertex][temp] = true;
                scanf("%d", &temp);
            }
        }

        for (int i = 1; i <= vertice_count; i++) {
            for (int j = 1; j <= vertice_count; j++) {
                // printf("%d ", adjacency_matrix[i][j]);
            }
            // printf("\n");
        }

        int count;
        scanf("%d", &count);
        for (int i = 0; i < count; i++) {
            memset(used, false, sizeof(used));
            int temp;
            scanf("%d", &temp);
            // printf("temp %d\n", temp);
            for (int j = 1; j <= vertice_count; j++) {
                // printf("adjacency_matrix[%d][%d] %d\n", temp, i,
                // adjacency_matrix[temp][i]);
                if (adjacency_matrix[temp][j] == true) {
                    used[j] = true;
                    // printf("dfs %d\n", j);
                    dfs(j);
                }
            }

            int counter = 0;
            for (int j = 1; j <= vertice_count; j++)
                if (used[j] == false)
                    counter++;

            if (counter)
                printf("%d ", counter);
            else
                printf("0\n");
            for (int j = 1; j <= vertice_count; j++) {
                if (used[j] == false) {
                    counter--;
                    if (counter)
                        printf("%d ", j);
                    else
                        printf("%d\n", j);
                }
            }
        }
    }

    return 0;
}
