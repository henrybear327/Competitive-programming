#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

#define M ((int) 1e6 + 3)

ll facDP[700100];
ll fac(ll a)
{
    return facDP[a];
}

ll fast_pow(ll base, ll exp, ll mod)
{
    if (exp == 0)
	return 1LL;
    ll res = 1;
    while (exp > 0) {
	if (exp & 1) {
	    res = ((res % mod) * (base % mod)) % mod;
	}
	exp >>= 1;
	base = ( (base % mod) * (base % mod) ) % mod;
    }
    return res;
}

ll inv(ll a) 
{
    return fast_pow(a, M - 2, M);
}

ll H(ll a, ll b)
{
    //printf("%lld %lld\n", a, fac(a));
    //printf("H %lld : %lld %lld %lld\n", a, fac(a + b), inv(fac(a)), inv(fac(b)));
    return (( (fac(a + b) % M) * inv(fac(a)) % M) % M ) * ( inv(fac(b)) % M);
}

int main()
{
    facDP[0] = 1;
    facDP[1] = 1;
    for(int i = 2; i <= 700010; i++) {
	facDP[i] = ((facDP[i - 1] % M) * (i % M)) % M;
    }

    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
	ans = ((ans % M) + H(i, m - 1)) % M;
    }
    printf("%lld\n", ans);

    return 0;
}
