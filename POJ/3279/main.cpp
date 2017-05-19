#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int n, m;

struct Data {
    int data[15][15];
    int flip[15][15];
};

void flip(Data &data, int x, int y)
{
    const int dx[5] = {0, 0, 1, -1, 0};
    const int dy[5] = {1, -1, 0, 0, 0};

    for (int i = 0; i < 5; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if ((0 <= xx && xx < n) && (0 <= yy && yy < m)) {
            data.data[xx][yy] ^= 1;
        }
    }
}

int res;
Data ans;

void go(int depth, Data &data)
{
    if (depth == n) {
        for (int i = 0; i < m; i++)
            if (data.data[depth - 1][i] == 1)
                return;

        int count1s = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (data.flip[i][j] == 1)
                    count1s++;

        if (count1s < res) {
            res = count1s;
            ans = data;
        }

        return;
    }

    for (int i = 0; i < m; i++) {
        if (data.data[depth - 1][i] == 1) {
            flip(data, depth, i);
            data.flip[depth][i] = 1;
        }
    }

    go(depth + 1, data);
}

int main()
{
    scanf("%d %d", &n, &m);

    Data orig;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &orig.data[i][j]);

    res = 1000;
    for (int i = 0; i < (1 << m); i++) {
        Data data = orig;
        memset(data.flip, 0, sizeof(data.flip));
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                data.flip[0][j] = 1;
                flip(data, 0, j);
            }
        }

        go(1, data);
    }

    // printf("%d\n", res);
    if (res == 1000) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                printf("%d%c", ans.flip[i][j], j == m - 1 ? '\n' : ' ');
    }
    return 0;
}
