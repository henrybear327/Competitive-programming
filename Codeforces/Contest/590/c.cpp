#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

/*
start only 2 4
end only 2 6

start:
1 -> 2
3 5 6 -> 4

prev - cur - transform to
2 - (1, 2) - 2
2 - (3, 4, 5, 6) - 4
3 - (1, 2) - 2
3 - (4, 5, 6) - 4
4 - (1, 2) - fucked
4 - (3, 5, 6) - 6
5 - (1, 2) - fucked
5 - (3, 4, 6) - 3
6 - (1, 2) - 2
6 - (3, 4, 5) - 5
*/

const int dx[] = {0, 1, 0, 0, 1, -1, 0};
const int dy[] = {0, 0, 1, 1, 0, 0, 1};

void solve()
{
    int n;
    scanf("%d", &n);

    int m[2][n];
    for (int i = 0; i < 2; i++) {
        char inp[n + 3];
        scanf("%s", inp);
        for (int j = 0; j < n; j++) {
            m[i][j] = inp[j] - '0';
        }
    }

    if (m[0][0] <= 2)
        m[0][0] = 2;
    else
        m[0][0] = 4;

    bool ok = true;
    int x = 0, y = 0;
    while (y < n) {
        // printf("%d %d\n", x, y);
        int orig = m[x][y];
        // move
        x += dx[orig];
        y += dy[orig];

        if (y == n)
            break;

        // change
        int &cur = m[x][y];
        // printf("moved to %d %d (orig %d)\n", x, y, orig);
        if (orig == 1)
            assert(1 == -1);
        else if (orig == 2) {
            if (cur <= 2)
                cur = 2;
            else {
                if (x == 0)
                    cur = 4;
                else
                    cur = 5;
            }
        } else if (orig == 3) {
            if (cur <= 2)
                cur = 2;
            else
                cur = 4;
        } else if (orig == 4) {
            if (cur <= 2) {
                ok = false;
                break;
            } else
                cur = 6;
        } else if (orig == 5) {
            if (cur <= 2) {
                ok = false;
                break;
            } else
                cur = 3;
        } else if (orig == 6) {
            if (cur <= 2) {
                cur = 2;
            } else
                cur = 5;
        }
    }

    if (ok == true && x == 1 && y == n) {
        if (m[1][n - 1] == 2 || m[1][n - 1] == 6)
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("NO\n");
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
