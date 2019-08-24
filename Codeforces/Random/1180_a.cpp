#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    1 - 1
    2 - 1 + 2 * 1 + 1
    3 - 1 + 2 * 3 + 1
    4 - 1 + 2 * 5 + 1
    5 - 1 + 2 * 7 + 1

    1 + 2(x - 2), x -> 2, 3, 4, 5...
    */

    int n;
    scanf("%d", &n);

    int dp[n + 1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (1 + (2 * ((i - 2) * 2 + 1)) + 1);
    }

    printf("%d\n", dp[n]);

    return 0;
}
