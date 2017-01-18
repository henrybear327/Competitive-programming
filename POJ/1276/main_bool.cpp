#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

bool dp[2][111111];
int main()
{
    int total, n;
    while (scanf("%d %d", &total, &n) == 2) {
        // read input
        vector<ii> coins;
        for (int i = 0; i < n; i++) {
            int cnt, val;
            scanf("%d %d", &cnt, &val);

            coins.push_back(ii(val, cnt));
        }

        /*
        printf("%d %d\n", total, n);
        for(int i = 0; i < n; i++) {
                printf("%d %d\n", coins[i].first, coins[i].second);
        }
        */

        // DP
        memset(dp, 0, sizeof(dp));

        // convert to log(n)
        vector<int> data;
        data.push_back(-1);
        for (int i = 0; i < n; i++) {
            int val = coins[i].first;
            int cnt = coins[i].second;

            int sum = 0;
            for (int j = 0; (1 << j) + sum <= cnt;
                 j++) { // split the coeff and mske sure the sum won't exceed cnt
                data.push_back(val * (1 << j));
                sum += (1 << j);
            }

            if (sum != cnt)
                data.push_back(val * (cnt - sum));
        }

        dp[0][0] = true;
        for (int i = 1; i < (int)data.size(); i++) {
            for (int j = 0; j <= total; j++) {
                if (j - data[i] >= 0)
                    dp[i % 2][j] = max((dp[(i % 2) ^ 1][j - data[i]] > 0) ? 1 : 0,
                                       (dp[(i % 2) ^ 1][j] > 0) ? 1 : 0);
                else
                    dp[i % 2][j] = (dp[(i % 2) ^ 1][j] > 0) ? 1 : 0;
            }
        }

        int mx = 0;
        for (int i = 1; i <= total; i++) {
            if (dp[n % 2][i] == 1)
                mx = i;
        }
        printf("%d\n", mx);
    }

    return 0;
}
