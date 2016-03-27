#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll ext_gcd(ll a, ll b, ll *x, ll *y)
{
    if(a == 0) {
	*x = 0;
	*y = 1;
	return b;
    }

    ll x1, y1;
    ll gcd = ext_gcd(b % a, a, &x1, &y1);

    *x = y1 - b / a * x1;
    *y = x1;

    return gcd;
}

int main()
{
    ll a, b;
    while(scanf("%lld %lld", &a, &b) == 2) {
	ll gcd, x = 0, y = 1;
	gcd = ext_gcd(a, b, &x, &y);

	if(a == b)
	    x = 0, y = 1;
	
	printf("%lld %lld %lld\n", x, y, gcd);
    }

    return 0;
}
