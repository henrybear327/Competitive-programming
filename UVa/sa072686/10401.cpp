#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll solve(char inp[])
{
    int n = strlen(inp);
    // printf("%s\n", inp);
    // printf("n = %d\n", n);

    ll dp[n][n];
    int queen[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int pos = 0;
        if ('1' <= inp[i] && inp[i] <= '9') {
            pos = inp[i] - '0';
        } else if ('A' <= inp[i] && inp[i] <= 'F') {
            pos = inp[i] - 'A' + 10;
        }
        pos--;
        // printf("%d %d\n", i, pos);
        queen[i] = pos;

        // check attack
        if (i > 0 && queen[i] != -1 && queen[i - 1] != -1) {
            if (abs(queen[i] - queen[i - 1]) <= 1)
                return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (queen[0] == -1)
            dp[i][0] = 1;
        else
            dp[queen[0]][0] = 1;
    }

    for (int i = 1; i < n; i++) { // col
        if (queen[i] == -1) {
            for (int j = 0; j < n; j++) {   // row
                for (int k = 0; k < n; k++) { // row
                    if (abs(k - j) > 1)
                        dp[j][i] += dp[k][i - 1];
                }
            }
        } else {
            for (int k = 0; k < n; k++) { // row
                if (abs(k - queen[i]) > 1)
                    dp[queen[i]][i] += dp[k][i - 1];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[i][n - 1];

    return ans;
}

int main()
{
    char inp[22];
    while (scanf("%s", inp) == 1) {
        printf("%lld\n", solve(inp));
    }

    return 0;
}
