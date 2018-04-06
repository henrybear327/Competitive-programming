#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    int board[4][n][n];
    for (int i = 0; i < 4; i++) {
        char inp[n + 2];
        for (int j = 0; j < n; j++) {
            scanf("%s", inp);
            for (int k = 0; k < n; k++)
                board[i][j][k] = inp[k] == '0' ? 0 : 1;
        }
    }
    /*
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d%c", board[i][j][k], k == n - 1 ? '\n' : ' ');
            }
        }
    }
    */

    int ans = INT_MAX;
    for (int i = 0; i < (1 << 4); i++) {
        // printf("i = %d\n", i);
        if (__builtin_popcount(i) != 2)
            continue;

        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if ((i >> j) & 1) { // 1 diamond
                // printf("first\n");
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        if (r % 2 == 0) {
                            if (c % 2 != board[j][r][c])
                                cnt++;
                        } else {
                            if (c % 2 == board[j][r][c])
                                cnt++;
                        }
                    }
                }
            } else { // 1 cross
                // printf("second\n");
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        if (r % 2 != 0) {
                            if (c % 2 != board[j][r][c])
                                cnt++;
                        } else {
                            if (c % 2 == board[j][r][c])
                                cnt++;
                        }
                    }
                }
            }
            // printf("cnt %d\n", cnt);
        }
        ans = min(ans, cnt);
        // printf("%d %d\n", i, cnt);
    }

    printf("%d\n", ans);

    return 0;
}
