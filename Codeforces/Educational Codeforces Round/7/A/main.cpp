#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

inline ll cal(ll n)
{
    return (n + 1) * n / 2;
}


int main()
{
    ll n;
    scanf("%lld", &n);

    ll x = ceil((-1 + sqrt(1 + 8 * n) ) / 2);

    ll tmp = cal(x);

    if(tmp == n)
	printf("%lld\n", x);
    else
	printf("%lld\n", n - cal(x - 1));

    return 0;
}
