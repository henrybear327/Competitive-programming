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
    long long int l, r, k;
    scanf("%lld %lld %lld", &l, &r, &k);

    long long int num = 1, has_out = 0;
    for (long long int i = 0; i < 65; i++) {
        if (l <= num && num <= r) {
            has_out = 1;
            printf("%lld ", num);
        }

        if (num > LLONG_MAX / k) {
            break;
        } else {
            num *= k;
        }
    }

    if (has_out == 0)
        printf("-1\n");

    return 0;
}
