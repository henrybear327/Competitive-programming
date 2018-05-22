#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        ll num;
        scanf("%lld", &num);

        ll sum;
        if (num % 2 == 0) // even
            sum = num / 2 * (1 + num);
        else
            sum = (num + 1) / 2 * num;

        int cnt = 0, num_orig = num;
        while (num) {
            cnt++;
            num >>= 1;
        }

        ll two_pow = 1;
        while (two_pow <= num_orig) {
            sum -= (2 * two_pow);
            two_pow <<= 1;
        }

        printf("%lld\n", sum);
    }

    return 0;
}
