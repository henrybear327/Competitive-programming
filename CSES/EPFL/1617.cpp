#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    const int MOD = 1e9 + 7;

    long long int ans = 1; // 2^0
    long long int base = 2;
    while (n > 0) {
        if (n & 1) {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        n >>= 1;
    }

    printf("%lld\n", ans);

    return 0;
}
