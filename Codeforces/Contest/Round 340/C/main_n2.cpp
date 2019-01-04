#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long int ll;

inline long long int cal(ll x, ll y, ll a, ll b)
{
    ll xx = x - a;
    ll yy = y - b;
    return xx * xx + yy * yy;
}

int main()
{
    int n, a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    pair<ll, ll> dist[2001]; 
    for(int i = 0; i < n; i++) {
	int x, y;
	scanf("%d %d", &x, &y);

	dist[i] = make_pair(cal(x, y, a, b), cal(x, y, c, d));
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i <= n; i++) { 
	// add a (0, 0) case, because the case of only r2 may be missing!
	ll r1 = dist[i].first;
	ll r2 = 0;
	for(int j = 0; j <= n; j++) {
	    if(dist[j].first > r1) 
		r2 = max(r2, dist[j].second);
	}

	ans = min(ans, r1 + r2);
    }

    printf("%lld\n", ans);

    return 0;
}
