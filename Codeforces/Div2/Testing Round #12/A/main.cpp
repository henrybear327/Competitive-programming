#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    ll k, a, b;
    scanf("%lld %lld %lld", &k, &a, &b);

    if (a == b) {
        printf("%d\n", a % k == 0 ? 1 : 0);
        return 0;
    }

    // 5 -7 -3
    // 3 124 456
    if (a % k) { // to right
        if (a > 0)
            a = a + k - a % k;
        else
            a = a - a % k;
    }

    if (a > b) {
        // 1000000000000000000 -2 -1
        printf("0\n");
        return 0;
    }

    if (b % k) { // to left
        if (b > 0)
            b = b - b % k;
        else
            b = b - (k - (b % k) * -1);
    }

    ll ans = 0;
    if (a == b)
        ans = 1;
    else
        ans = llabs(a - b) / k + 1;

    printf("%lld\n", ans);

    return 0;
}
