#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

/*
LCM
a * b / gcd(a,b)
*/

int main()
{
    long long int t, w, b;
    scanf("%lld %lld %lld", &t, &w, &b);

    long long int minn = min(w, b);

    long long int gcdd = gcd(w, b);

    long long int lcm = 0;
    if (w * b > 0) {
        // no overflow
        lcm = w * b / gcdd;
    }

    long long int makeup = minn;
    if (lcm != 0) {
        long long int tmp = t / lcm;
        if (minn > t - tmp * lcm)
            makeup = t - tmp * lcm + 1;
    }

    long long int factor = lcm != 0 ? (t / lcm - 1) * minn + makeup : 0;
    long long int numerator = minn - 1 + factor;

    gcdd = gcd(numerator, t);

    printf("%lld/%lld\n", numerator / gcdd, t / gcdd);

    return 0;
}
