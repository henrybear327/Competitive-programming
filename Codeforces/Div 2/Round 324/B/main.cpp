#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int M = 1000000007;

    long long int a = 27, b = 7;
    for (int i = 3; i < 3 * n; i++) {
        a *= 3;
        a %= M;
    }
    for (int i = 1; i < n; i++) {
        b *= 7;
        b %= M;
    }
    //(3^(3n) - 7^n) % M;
    long long int ans = (a - b + M) % M;

    printf("%lld\n", ans);
    return 0;
}
