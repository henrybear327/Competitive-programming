#include <bits/stdc++.h>

using namespace std;

#ifdef WIN_32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long ll;

int main()
{
    int n, d, c;
    scanf("%d %d %d", &n, &d, &c);

    ll t[n + 10];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t[i]);
    }

    ll DP[n + 10];
    DP[0] = 0;
    for (int i = 1; i <= n; i++) {
        DP[i] = DP[i - 1] + d; // base case
        ll partial_cost = 0;
        for (int j = i - 1; j >= 1; j--) {
            partial_cost += t[i] - t[j];
            printf("partial_cost %d %d %lld\n", i, j, partial_cost);
            DP[i] = min(DP[i], DP[j - 1] + d + partial_cost * c);
        }
    }
    printf("%lld\n", DP[n]);

    return 0;
}
