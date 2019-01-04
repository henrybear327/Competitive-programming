#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    ll n;
    scanf("%lld", &n);

    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if(n < b)
        printf("%lld\n", n / a);
    else if(n < a)
        printf("%lld\n", (n - c) / (b - c));
    else {
        if(a <= b - c)
            printf("%lld\n", n / a);
        else {
            ll b_cnt = (n - c) / (b - c);
            printf("%lld\n", b_cnt + (n - (b - c) * b_cnt) / a);
        }
    }

    return 0;
}
