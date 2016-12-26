#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

#define DEBUG 0

int row, col;
inline bool in_bonud(int x, int y)
{
    return 0 <= x && x < row && 0 <= y && y < col;
}

bool m[510][510];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int get_cnt(int x, int y)
{
    int ans = 0;
    if (m[x][y] == false)
        return ans;

    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (in_bonud(xx, yy) && m[xx][yy]) {
            ans++;
        }
    }
    return ans;
}

int minus_boundary(int a, int b, int c, int d)
{
    int ans = 0;
    // right and left
    for (int i = b + 1; i < d; i++) {
        if (m[a][i] && in_bonud(a - 1, i) && m[a - 1][i])
            ans++;
        if (m[c][i] && in_bonud(c + 1, i) && m[c + 1][i])
            ans++;
    }

    // down and up
    for (int i = a + 1; i < c; i++) {
        if (m[i][d] && in_bonud(i, d + 1) && m[i][d + 1])
            ans++;
        if (m[i][b] && in_bonud(i, b - 1) && m[i][b - 1])
            ans++;
    }

    if (m[a][b] && in_bonud(a - 1, b) && m[a - 1][b])
        ans++;
    if (m[a][b] && in_bonud(a, b - 1) && m[a][b - 1])
        ans++;
    if (m[a][d] && in_bonud(a - 1, d) && m[a - 1][d])
        ans++;
    if (m[a][d] && in_bonud(a, d + 1) && m[a][d + 1])
        ans++;
    if (m[c][b] && in_bonud(c, b - 1) && m[c][b - 1])
        ans++;
    if (m[c][b] && in_bonud(c + 1, b) && m[c + 1][b])
        ans++;
    if (m[c][d] && in_bonud(c + 1, d) && m[c + 1][d])
        ans++;
    if (m[c][d] && in_bonud(c, d + 1) && m[c][d + 1])
        ans++;

    return ans;
}

int main()
{
    scanf("%d %d", &row, &col);

    for (int i = 0; i < row; i++) {
        char inp[1000];
        scanf("%s", inp);

        for (int j = 0; j < col; j++) {
            m[i][j] = inp[j] == '.' ? true : false;
        }
    }

#if DEBUG == 1
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", m[i][j] == true ? '.' : '#');
        }
        printf("\n");
    }
#endif

    int mcnt[row][col];
    memset(mcnt, 0, sizeof(mcnt));

    // get cnt for all cells
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mcnt[i][j] = get_cnt(i, j);
        }
    }

#if DEBUG == 1
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d%c", mcnt[i][j], j == col - 1 ? '\n' : ' ');
        }
    }
#endif

    // get prefix sum
    for (int i = 1; i < col; i++)
        mcnt[0][i] = mcnt[0][i - 1] + mcnt[0][i];
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++)
            mcnt[i][j] = mcnt[i][j - 1] + mcnt[i][j];

        for (int j = 0; j < col; j++)
            mcnt[i][j] = mcnt[i][j] + mcnt[i - 1][j];
    }

#if DEBUG == 1
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d%c", mcnt[i][j], j == col - 1 ? '\n' : ' ');
        }
    }
#endif

    // now take the query
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        a--;
        b--;
        c--;
        d--;

        int first = mcnt[c][d];
        int second;
        if (a == 0 || b == 0)
            second = 0;
        else
            second = mcnt[a - 1][b - 1];
        int third;
        if (b == 0)
            third = 0;
        else
            third = mcnt[c][b - 1];
        int forth;
        if (a == 0)
            forth = 0;
        else
            forth = mcnt[a - 1][d];

        int ans = first + second - third - forth;
        // printf("%d %d %d %d\n", first, second, third, forth);

        // printf("%d\n", ans);
        ans -= minus_boundary(a, b, c, d);
        // printf("%d\n", ans);

        // printf("final %d\n", ans / 2);
        printf("%d\n", ans / 2);
    }

    return 0;
}
