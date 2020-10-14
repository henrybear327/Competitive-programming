#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
long long fast_pow(long long base, long long exp)
{
    long long b = base;
    long long ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= b;
            ret %= mod;
        }
        b *= base;
        b %= mod;
        exp >>= 1;
    }

    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%lld\n", fast_pow(2, n));

    return 0;
}
