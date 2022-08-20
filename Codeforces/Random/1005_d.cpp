#include <bits/stdc++.h>

using namespace std;

int main()
{
    // max lenght = 3
    // 11121222 -> Danby greedy fail

    char inp[200010];
    scanf("%s", inp);

    int len = strlen(inp);
    int dp[2][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
        int num = 0;
        if ((inp[i] - '0') % 3 == 0)
            dp[0][i] = 1;
        for (int j = 0; j < 3; j++) {
            if (i - j >= 0) {
                num += inp[i - j] - '0';

                // v
                if (num % 3 == 0) {
                    if (j > 0 && inp[i - j] == '0') {
                        // x
                        goto nope;
                    } else {
                        dp[0][i] = max(1, dp[0][i]);
                        if (i - j - 1 >= 0) {
                            dp[0][i] =
                                max(dp[0][i], max(dp[0][i - j - 1], dp[1][i - j - 1]) + 1);
                        }
                    }
                }
nope:
                // x
                if (i - j - 1 >= 0) {
                    dp[1][i] = max(dp[1][i], max(dp[0][i - j - 1], dp[1][i - j - 1]));
                }
            }
        }
    }

    /*
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < len; i++)
            printf("%d ", dp[j][i]);
        printf("\n");
    }
    */
    printf("%d\n", max(dp[0][len - 1], dp[1][len - 1]));

    return 0;
}
