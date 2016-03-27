#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int employee;
    while (scanf("%d", &employee) == 1) {
        vector<int> graph[2505];

        for (int i = 0; i < employee; i++) {
            graph[i].clear();
            int tmp;
            scanf("%d", &tmp);

            for (int j = 0; j < tmp; j++) {
                int tmp2;
                scanf("%d", &tmp2);
                graph[i].push_back(tmp2);
            }
        }

        int cases;
        scanf("%d", &cases);

        for (int i = 0; i < cases; i++) {
            int inp;
            scanf("%d", &inp);

            int visited[employee];
            memset(visited, 0, sizeof(visited));

            queue<int> bfs;
            bfs.push(inp);
            visited[inp] = 1;

            int tmp_max = 0, max = 0, size = 1, day = 0;
            while (bfs.size()) {
                int curr = bfs.front();
                bfs.pop();

                /*
                for (vector<int>::iterator i = graph[curr].begin();
                     i != graph[curr].end(); i++) {
                    if (visited[*i] == 0) {
                        tmp_max++;
                        bfs.push(*i);
                        visited[*i] = visited[curr] + 1;
                        // printf("%d, %d\n", i, visited[i]);
                    }
                }
                */

                for (int i = 0; i < (int)graph[curr].size(); i++) {
                    if (visited[graph[curr][i]] == 0) {
                        tmp_max++;
                        bfs.push(graph[curr][i]);
                        visited[graph[curr][i]] = visited[curr] + 1;
                        // printf("%d, %d\n", i, visited[i]);
                    }
                }

                if (--size == 0) {
                    size = bfs.size();
                    if (tmp_max > max) {
                        max = tmp_max;
                        day = visited[curr];
                    }
                    tmp_max = 0;
                }
            }
            if (max == 0)
                printf("0\n");
            else
                printf("%d %d\n", max, day);
        }
    }

    return 0;
}
