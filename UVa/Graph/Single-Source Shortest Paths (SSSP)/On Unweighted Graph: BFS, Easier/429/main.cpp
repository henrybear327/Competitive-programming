#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

// each word is a vertex, connect 2 words with an edge if differ by 1 letter

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar(); // dangling \n after scanf
    getchar(); // Getline before first test case
    while (cases--) {
        char dictionary[210][50];

        int index = 0;
        while (fgets(dictionary[index], 50, stdin) != NULL &&
               dictionary[index][0] != '*') {
            dictionary[index][strlen(dictionary[index]) - 1] = '\0';
            index++;
        }

        int graph[index][index];
        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                if (strlen(dictionary[i]) != strlen(dictionary[j]))
                    continue;

                int len = strlen(dictionary[i]), count = 0;
                for (int k = 0; k < len; k++) {
                    if (dictionary[i][k] == dictionary[j][k])
                        count++;
                }
                if (count == len - 1)
                    graph[i][j] = graph[j][i] = 1;
            }
        }

        char query[1000];
        while (fgets(query, 1000, stdin) != NULL && query[0] != '\n') {
            char *s, *e;
            s = strtok(query, " \n");
            e = strtok(NULL, " \n");

            if (strcmp(s, e) == 0) {
                printf("%s %s 0\n", s, e);
                continue;
            }

            int s_idx = 0;
            for (int i = 0; i < index; i++)
                if (strcmp(s, dictionary[i]) == 0)
                    s_idx = i;

            int visited[index];
            int ans = 1;
            memset(visited, 0, sizeof(visited));

            queue<int> bfs;
            bfs.push(s_idx);
            visited[s_idx] = 1;

            while (bfs.size()) {
                int curr = bfs.front();
                bfs.pop();

                if (strcmp(dictionary[curr], e) == 0) {
                    ans = visited[curr];
                    break;
                }

                for (int i = 0; i < index; i++) {
                    if (graph[curr][i] == 1 && visited[i] == 0) {
                        bfs.push(i);
                        visited[i] = visited[curr] + 1;
                    }
                }
            }

            printf("%s %s %d\n", s, e, ans - 1);
        }
        if (cases)
            printf("\n");
    }

    return 0;
}
