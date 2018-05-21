#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const double EPS = 1e-7;
double solve()
{
    int n, p;
    scanf("%d %d\n", &n, &p);

    ii inp[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        sum += 2 * (inp[i].first + inp[i].second);
    }

    // weight, value
    // 2 * min(w, h), 2 * sqrt(w * w + h * h)
    double dp[55555];
    fill(dp, dp + 55555, -1e10);
    for (int i = 0; i < n; i++) {
        int w = inp[i].first;
        int h = inp[i].second;
        int weight = 2 * min(w, h);
        double value = 2.0 * sqrt(w * w + h * h);

        // printf("%d %d\n", w, h);
        // printf("%d %d %f\n", i, weight, value);

        dp[0] = 0;
        for (int j = 55555 - 1; j >= 0; j--) {
            if (j - weight >= 0 && dp[j - weight] >= 0) {
                dp[j] = max(dp[j], dp[j - weight] + value);
            }
        }
    }

    double ans = 0;
    double target = p - sum; // difference to make up
    // printf("%f\n", target);
    // i <= target means only when at least i is added, we can use dp[i]
    for (int i = 0; i < 55555 && i <= target; i++) {
        // printf("%d %f\n", i, dp[i]);

        if (dp[i] >= 0) {
            // WOW! can add range is [i, dp[i]]

            // printf("%d %f\n", i, dp[i]);
            // if (i * 1.0 + dp[i] >= target)
            ans = max(ans, min(target, dp[i]));
        }
    }

    return sum + ans;
    // return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %.15f\n", i, solve());
    }
    return 0;
}
