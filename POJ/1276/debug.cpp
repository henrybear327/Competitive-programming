#include <stdio.h>
#include <string.h>
#define MAX 100010
#define max(x,y) (x > y ? x : y)

int main(void)
{
    int cash, N, n[20], n2[20], D[20], D2[20], dp[2][MAX], i, j, k, check[1010], num;
    while(scanf("%d %d", &cash, &N) == 2) {
    for (i = 0; i < N; i++)
        scanf("%d %d", &n[i], &D[i]);
    for (i = 0; i < MAX; i++)
        dp[0][i] = dp[1][i] = 0;
    for (i = 0; i < 1010; i++)
        check[i] = 0;
    k = 0;
    for (i = 0; i < N; i++) {
        num = n[i];
        for (j = 1; num >= j;) {
            num -= j;
            check[j]++;
            j *= 2;
        }
        if (num != 0)
            check[num]++;
        for (j = 0; j < n[i]; j++)
            if (check[j] != 0) {
                n2[k] = check[j];
                D2[k] = j * D[i];
                k++;
                check[j] = 0;
            }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= cash; j++) {
            if (j - D2[i] >= 0)
                dp[i % 2][j] =
                    max(dp[(i % 2) ^ 1][j - D2[i]] + D2[i], dp[(i % 2) ^ 1][j]);
            else
                dp[i % 2][j] = dp[(i % 2) ^ 1][j];
        }
    }

    /*
    for (i = 0; i < N; i++) {
        for (j = cash; j >= D2[i]; j--) {
            for (k = n2[i]; k > 0; k--) {
                if (k * D2[i] > j)
                    continue;
                dp[j] = (dp[j] > (dp[j - k * D2[i]] + k * D2[i]))
                        ? dp[j]
                        : (dp[j - k * D2[i]] + k * D2[i]);
            }
        }
    }
    */
    printf("%d\n", dp[k % 2][cash]);
}
return 0;
}
