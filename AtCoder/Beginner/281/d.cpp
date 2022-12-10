#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, _k, d;
    scanf("%d %d %d", &n, &_k, &d);

    int inp[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i + 1]);
    }

    ll dp[n + 1][_k + 1][d];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) { // use the number [1, i]
		// when we add a new number, we are essentially trying to see if the current number can improve our previous round results!
		
        dp[i][0][0] = 0; // so the "use" case where the previous round doesn't have value will work
        for (int j = 1; j <= _k; j++) { // using at most j numbers from [1, i]
            for (int k = 0; k < d; k++) { // we enumerate all remainders
                // not use
                if (dp[i - 1][j][k] != -1) {
                    dp[i][j][k] = dp[i - 1][j][k]; // we re-use the value from previous [1, i - 1]
                }

                // use
                int prevRem = (k - (inp[i] % d) + d) % d;
                if (dp[i - 1][j - 1][prevRem] != -1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][prevRem] + inp[i]);
                }
            }
        }
    }

    printf("%lld\n", dp[n][_k][0]);

    return 0;
}
