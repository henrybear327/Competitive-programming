#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int matrix[11][11];

int main()
{
    int node;
    scanf("%d", &node);

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < node; i++) {
        if (i == 0)
            printf("1\n");
        else {
            // do BFS
            int visited[node];
            memset(visited, 0, sizeof(visited));

            queue<int> bfs;
            int step = 0;
            visited[i] = 1;
            for (int j = 0; j < node; j++) {
                if (matrix[j][i] == 1 && visited[j] == 0) {
                    bfs.push(j);
                    step = 1;
                }
            }

            int queue_size = bfs.size();

            while (bfs.size() != 0) {
                int curr = bfs.front();
                if (curr == 0)
                    break;
                else {
                    visited[curr] = 1;
                    for (int j = 0; j < node; j++) {
                        if (matrix[j][curr] == 1 && visited[j] == 0) {
                            bfs.push(j);
                        }
                    }
                }
                /*
                                printf("visited: ");
                                for (int j = 0; j < node; j++)
                                    printf("%d ", visited[j]);
                                printf("\n");
                */
                bfs.pop();
                queue_size--;
                // printf("size %d\n", queue_size);
                if (queue_size == 0) {
                    queue_size = bfs.size();
                    step++;
                }
                // printf("size %d, step %d\n", queue_size, step);
            }

            printf("%d\n", step + 1);
        }
    }

    return 0;
}
