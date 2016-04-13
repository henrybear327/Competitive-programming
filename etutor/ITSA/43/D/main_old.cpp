#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int node, start, endd, mid;
bool map[110][110];

int min_dist;

typedef struct info {
    int step, cnt;
    bool lock;
} Info;

Info visited[110];

void bfs()
{
    memset(visited, 0, sizeof(visited));

    visited[start].cnt = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        // printf("curr pop %d\n", curr);

        q.pop();
        // printf("curr %d %d %d\n", curr, visited[curr].cnt, visited[curr].step);

        for (int i = 0; i < node; i++) {
            if (visited[curr].lock == false && visited[i].lock == false &&
                map[curr][i] == true) {
                // printf("i %d %d %d\n", i, visited[i].cnt, visited[i].step);
                if (visited[i].cnt == 0) {
                    visited[i].cnt = visited[curr].cnt;
                    visited[i].step = visited[curr].step + 1;
                } else if (visited[i].step == visited[curr].step + 1) {
                    visited[i].cnt += visited[curr].cnt;
                } else if (visited[i].step > visited[curr].step) {
                    visited[i].cnt = visited[curr].cnt;
                    visited[i].step = visited[curr].step + 1;
                }
                q.push(i);
                // printf("ii %d %d %d\n", i, visited[i].cnt, visited[i].step);
            }
        }
        visited[curr].lock = true;
    }
}
int mid_ans, total_ans;
/*
void dfs(int curr, int v[], int step)
{
    if (step == min_dist) {
        if (curr == endd) {
            if (v[mid] == 1) {
                mid_ans++;
            }
            total_ans++;
        }

        return;
    }

    for (int i = 0; i < node; i++) {
        if (v[i] == 0 && map[curr][i] == true) {
            v[i] = 1;
            dfs(i, v, step + 1);
            v[i] = 0;
        }
    }
}
*/

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d,%d,%d,%d", &node, &start, &endd, &mid);
        start--;
        endd--;
        mid--;

        for (int i = 0; i < node; i++) {
            for (int j = 0; j < node; j++) {
                int tmp;
                scanf("%d", &tmp);

                map[i][j] = tmp == 1 ? true : false;
            }
        }

        mid_ans = 0;
        total_ans = 0;

        bfs();
        total_ans = visited[endd].cnt;

        int orig_start = start, orig_endd = endd, orig_mid = mid;
        endd = mid;
        bfs();
        int ans = visited[endd].cnt;

        start = orig_mid;
        endd = orig_endd;
        bfs();
        ans *= visited[endd].cnt;

        printf("%d %d\n", total_ans, ans);
    }

    return 0;
}
