#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;

const int value[5] = {1, 5, 10, 25, 50};

int main()
{
    ll dp[7490];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j + value[i] < 7490; j++) {
            dp[j + value[i]] += dp[j];
        }
    }

    int n;
    while (scanf("%d", &n) == 1) {
        printf("%llu\n", dp[n]);
    }

    return 0;
}
