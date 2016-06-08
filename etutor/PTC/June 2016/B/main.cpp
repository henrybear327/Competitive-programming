#include <bits/stdc++.h>
using namespace std;

const int MAX_M = 200;
const int MAX_C = 20;
const int MAX_K = 20;
int M, C, K;
int dp[MAX_C][MAX_M + 1];
int cost[MAX_C][MAX_K];
int n[MAX_C];

int main() {
    // dp[i][j] = 前 i + 1 個 regions 可否組出成本 j
    // dp[i][j] = true if any(dp[i - 1][j - cost[i][x]] for 0 <= x < n[i])

    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &M, &C);
        for (int i = 0; i < C; i++) {
            scanf("%d", &n[i]);
            for (int j = 0; j < n[i]; j++) {
                scanf("%d", &cost[i][j]);
            }
        }

        memset(dp, false, sizeof(dp));
        for (int j = 0; j < n[0]; j++)
            dp[0][cost[0][j]] = true;

        // for (int i = 0; i < C; i++) {
        //     for (int j = 0; j < n[i]; j++) {
        //         cout << cost[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // puts("--------------");

        // for (int j = 0; j <= M; j++) {
        //     printf("dp[%d][%d] = %d\n", 0, j, dp[0][j]);
        // }

        for (int i = 1; i < C; i++) {
            for (int j = 1; j <= M; j++) {
                for (int x = 0; x < n[i]; x++) {
                    if (j - cost[i][x] < 0)
                        continue;
                    dp[i][j] = (dp[i][j] or dp[i - 1][j - cost[i][x]]);
                }
            }

            // for (int j = 0; j <= M; j++) {
            //     printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            // }
        }

        bool has_ans = false;
        for (int i = M; i >= 0; i--) {
            if (dp[C - 1][i]) {
                has_ans = true;
                printf("%d\n", i);
                break;
            }
        }

        if (!has_ans) {
            puts("plan failure");
        }
    }

    return 0;
}