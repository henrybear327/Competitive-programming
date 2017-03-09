#include <cstdio>
#include <cstring>

using namespace std;

#define BLACK 0
#define RED 1
#define HUMAN 2

int data[22][22];
bool seen[22][22];
int hx, hy;
int w, h;
bool read()
{
    if(scanf("%d %d", &w, &h) != 2 || (w == 0 && h == 0))
        return false;

    for(int i = 0; i < h; i++) {
        char inp[1000];
        scanf("%s", inp);

        for(int j = 0; j < w; j++) {
            char c = inp[j];

            if(c == '.')
                data[i][j] = BLACK;
            else if(c == '#')
                data[i][j] = RED;
            else {
                data[i][j] = HUMAN;
                hx = i;
                hy = j;
            }
        }
    }

    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         printf("%d%c", data[i][j], j == w - 1 ? '\n' : ' ');
    //     }
    // }

    return true;
}

int ans;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool inBound(int x, int y)
{
    return (0 <= x && x < h) && (0 <= y && y < w);
}

void dfs(int x, int y)
{
    if(seen[x][y] == true)
        return;
    if(data[x][y] == RED)
        return;

    seen[x][y] = true;

    ans++;
    // printf("%d %d\n", x, y);

    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(inBound(xx, yy))
            dfs(xx, yy);
    }
}

int main()
{
    while(read()) {
        memset(seen, false, sizeof(seen));
        ans = 0;
        dfs(hx, hy);

        printf("%d\n", ans);
    }

    return 0;
}