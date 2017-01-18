#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int dp[2][100010];

typedef pair<int, int> ii;
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        vector<ii> coins;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            coins.push_back(ii(x, 0));
        }
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            coins[i].second = x;
        }

        vector<int> items;
        items.push_back(-1);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int cnt = coins[i].second;
            for (int j = 0; (1 << j) + sum <= cnt; j++) {
                items.push_back(coins[i].first * (1 << j));
                sum += (1 << j);
            }

            if (sum != cnt)
                items.push_back(coins[i].first * (cnt - sum));
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < (int)items.size(); i++) {
            for (int j = 0; j <= m; j++) {
                if (j - items[i] >= 0) {
                    dp[i % 2][j] =
                        max(dp[(i % 2) ^ 1][j], dp[(i % 2) ^ 1][j - items[i]] + items[i]);
                } else {
                    dp[i % 2][j] = dp[(i % 2) ^ 1][j];
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += dp[(items.size() - 1) % 2][i] == i ? 1 : 0;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
