#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll mod = 1e9 + 7;
ll fastPow(ll base, ll exp)
{
    ll ans = 1;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }

        exp >>= 1;
        base *= base;
        base %= mod;
    }

    return ans;
}

int main()
{
    // eat all 1s first
    // 1111111
    // 2^n - 1

    // 11100
    // _2211 __433 ___77 ____14
    // 2^3-1

    // 1000
    // _111 __22 ___4

    // x 1s: 1 2 4 8 16 32 -> sum = 2^x-1
    // y 0s: 0 1 3 7 15 31 -> starting = 2^x - 1, sum = starting + starting * 2 +
    // starting * 4 + ... + starting * 2^(y-1) = starting * (1 - 2^y) / (1 - y)

    int n, q;
    scanf("%d %d", &n, &q);

    char inp[n + 3];
    scanf("%s", inp);

    int pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (inp[i - 1] == '1');

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        int x = pre[r] - pre[l - 1];
        int y = r - l + 1 - x;

        // printf("%d %d %d %d\n", l, r, x, y);

        ll ans = 0;
        ans += fastPow(2, x) - 1;
        ans %= mod;
        ans += (fastPow(2, x) - 1) * (fastPow(2, y) - 1);
        ans %= mod;
        printf("%lld\n", ans);
    }

    return 0;
}
