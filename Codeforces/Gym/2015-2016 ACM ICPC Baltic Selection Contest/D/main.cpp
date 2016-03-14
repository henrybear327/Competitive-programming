#include <bits/stdc++.h>

using namespace std;

int ans, town, wilderness;
int v[510][510];
char g[510][510];

int n, m;
int a, b;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool bounded(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int bfs()
{
    queue< pair<int, int> >q;
    q.push(make_pair(0, 0));
    int visited[510][510];
    visited[0][0]= 1;
    memset(visited, 0, sizeof(visited));
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if(curr.first == n - 1 && curr.second == m - 1)
            break;

        for(int i = 0; i < 4; i++) {
            int x1 = curr.first + dir[i][0];
            int y1 = curr.second + dir[i][1];

            if (bounded(x1, y1) && visited[x1][y1] == 0 && g[x1][y1] == '.') {
                q.push(make_pair(x1, y1));
                visited[x1][y1]= visited[curr.first][curr.second] + 1;
            }
        }
    }

    return visited[n - 1][m - 1];
}
int main()
{
    while (scanf("%d %d", &m, &n) == 2) {
        scanf("%d %d", &a, &b);
        town = 0;
        wilderness = 0;
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }

        memset(v, 0, sizeof(v));
        int cnt = bfs();

        if(cnt < n + m - 2)
            ans = INT_MAX;
        else {
            if(cnt % 2 == 0) {
                ans = cnt / 2 * a + cnt / 2 * b;
            } else {
                ans = cnt / 2 * a + (cnt / 2 + 1) * b;
            }
        }

        if (ans == INT_MAX)
            printf("IMPOSSIBLE\n");
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
