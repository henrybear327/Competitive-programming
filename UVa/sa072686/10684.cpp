#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int dp[n], inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);
        dp[0] = inp[0];
        for (int i = 1; i < n; i++)
            dp[i] = max(inp[i], dp[i - 1] + inp[i]);

        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
            mx = max(mx, dp[i]);

        if (mx <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", mx);
    }

    return 0;
}
