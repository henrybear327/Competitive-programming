#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

/*
Good one
Do it reversely!
2 路線 2 起點 1 終點 -> 回朔字典序GG
變
2 路線 1 起點 2 終點 -> 回朔字典序KO
5 4
9 1 9 9
1 9 9 9
9 9 9 9
1 1 1 1
9 9 1 9
5 6
-3 -4 -1 -2 -8 -6
-6 -1 -8 -2 -7 -4
-5 -9 -3 -9 -9 -5
-8 -4 -1 -3 -2 -6
-3 -7 -2 -8 -6 -4
*/

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int inp[n][m];
        for (int i = 0; i < n; i++) {
            // for (int j = 0; j < m; j++) {
            for (int j = m - 1; j >= 0; j--) {
                scanf("%d", &inp[i][j]);
            }
        }

        int dp[n][m], from[n][m];
        memset(from, -1, sizeof(from));
        for (int i = 0; i < n; i++) {
            fill(dp[i], dp[i] + m, INT_MAX);
            dp[i][0] = inp[i][0];
        }

        for (int col = 0; col < m - 1; col++) {
            for (int row = 0; row < n; row++) {
                for (int i = -1; i <= 1; i++) {
                    int nr = row + i;
                    if (nr < 0) {
                        nr = n - 1;
                    } else if (nr >= n) {
                        nr = 0;
                    }

                    // printf("%d %d, %d %d\n", row, col, nr, col + 1);
                    // printf("%d %d\n", dp[row][col], dp[nr][col + 1]);

                    if (dp[row][col] + inp[nr][col + 1] < dp[nr][col + 1]) {
                        dp[nr][col + 1] = dp[row][col] + inp[nr][col + 1];
                        from[nr][col + 1] = row;
                    } else if (dp[row][col] + inp[nr][col + 1] == dp[nr][col + 1]) {
                        from[nr][col + 1] = min(from[nr][col + 1], row);
                    }
                }
            }

            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++)
            //         printf("%10d ", dp[i][j]);
            //     printf("\n");
            // }
            // puts(" ");
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++)
            //         printf("%10d ", from[i][j] + 1);
            //     printf("\n");
            // }
            // puts(" ");
            // puts(" ");
        }

        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[i][m - 1] < mn) {
                mn = dp[i][m - 1];
            }
        }
        // printf("mn %d\n", mn);

        vector<vector<int>> ans;
        for (int j = 0; j < n; j++) {
            int who = j;
            if (dp[who][m - 1] != mn)
                continue;
            vector<int> path;
            path.push_back(who);
            for (int i = m - 1; i >= 1; i--) {
                if (who == -1)
                    break;
                who = from[who][i];
                path.push_back(who);
            }

            if ((int)path.size() == m && who != -1) {
                // reverse(path.begin(), path.end());
                ans.push_back(path);
            }
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans[0].size(); i++) {
            printf("%d%c", ans[0][i] + 1, i == (int)ans[0].size() - 1 ? '\n' : ' ');
        }
        printf("%d\n", mn);
    }

    return 0;
}
