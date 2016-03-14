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
    while (scanf("%d", &n) == 1) {
        while (n--) {
            long long int a, b;
            scanf("%lld %lld", &a, &b);

            printf("%.15f\n", 1.0 / a - 1.0 / (b + 1));
        }
    }
    return 0;
}
