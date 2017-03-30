#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

inline bool bound(int x, int y)
{
    return (0 <= x && x <= 302) && (0 <= y && y <= 302);
}

int data[302][302];
int main()
{
    int m;
    scanf("%d", &m);

    memset(data, -1, sizeof(data));

    for (int i = 0; i < m; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);

        if (data[x][y] == -1)
            data[x][y] = t;
        else
            data[x][y] = min(data[x][y], t);

        for (int j = 0; j < 4; j++) {
            int xx = x + dx[j];
            int yy = y + dy[j];

            if (bound(xx, yy)) {
                if (data[xx][yy] == -1)
                    data[xx][yy] = t;
                else
                    data[xx][yy] = min(data[xx][yy], t);
            }
        }
    }

    /*
       for(int i = 0; i < 5; i++)
       for(int j = 0; j < 5; j++)
       printf("%3d%c", data[i][j], j == 4 ? '\n' : ' ');
     */

    iii loc = iii(ii(0, 0), 0);
    queue<iii> q;

    if (data[0][0] != 0)
        q.push(loc);

    int ans = -1;
    int seen[302][302];
    memset(seen, -1, sizeof(seen));
    seen[0][0] = 0;
    while (q.empty() == false) {
        iii cur = q.front();
        q.pop();

        int x = cur.first.first;
        int y = cur.first.second;
        int t = cur.second;

        if (data[x][y] == -1) {
            ans = t;
            break;
        }

        // printf("%d %d %d\n", cur.first.first, cur.first.second, cur.second);

        for (int j = 0; j < 4; j++) {
            int xx = x + dx[j];
            int yy = y + dy[j];

            if (bound(xx, yy)) {
                if ((data[xx][yy] == -1) || (t + 1 < data[xx][yy])) {
                    if (seen[xx][yy] == -1) {
                        q.push(iii(ii(xx, yy), t + 1));
                        seen[xx][yy] = t + 1;
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
