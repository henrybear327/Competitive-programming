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
    double l, p, q;
    scanf("%lf %lf %lf", &l, &p, &q);

    double t = l / (p + q);

    printf("%f\n", p * t);

    return 0;
}
