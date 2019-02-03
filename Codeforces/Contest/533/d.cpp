#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
    int x, y, p;
    int r;
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

inline bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    int s[p + 1];
    int cnt[p + 1];
    for (int i = 1; i < p + 1; i++)
        scanf("%d", &s[i]), cnt[i] = 0;

    char inp[n][m + 3];
    for (int i = 0; i < n; i++)
        scanf("%s", inp[i]);

    queue<Data> q;
    vector<ii> pos[p + 1]; // GG this stupid bug
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ('1' <= inp[i][j] && inp[i][j] <= '9')
                pos[inp[i][j] - '0'].push_back({i, j});
    for (int i = 1; i <= p; i++) // GG this stupid bug
        for (auto j : pos[i])
            q.push(Data{j.first, j.second, i, 0}), cnt[i]++;

    while (q.size() > 0) {
        queue<Data> curQ;
        int curP = q.front().p;
        while (q.size() > 0 && q.front().p == curP) {
            curQ.push(q.front());
            q.pop();
        }

        while (curQ.size() > 0) {
            Data cur = curQ.front();
            // printf("%d %d %d %d\n", cur.x, cur.y, cur.p, cur.r);
            curQ.pop();
            for (int i = 0; i < 4; i++) {
                int xx = cur.x + dx[i];
                int yy = cur.y + dy[i];
                if (ok(xx, yy, n, m) && inp[xx][yy] == '.') {
                    // printf("ok %d %d\n", xx, yy);
                    inp[xx][yy] = curP + '0';
                    cnt[curP]++;
                    if (cur.r == s[curP] - 1)
                        q.push(Data{xx, yy, curP, 0});
                    else
                        curQ.push(Data{xx, yy, curP, cur.r + 1});
                }
            }
        }
    }

    for (int i = 1; i <= p; i++)
        printf("%d ", cnt[i]);

#ifdef DEBUG
    printf("\n\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", inp[i]);
#endif
    return 0;
}
