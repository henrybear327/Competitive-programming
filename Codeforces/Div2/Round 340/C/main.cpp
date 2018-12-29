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

    pair<ll, ll> dist[2000]; 
    for(int i = 0; i < n; i++) {
	int x, y;
	scanf("%d %d", &x, &y);

	dist[i] = make_pair(cal(x, y, a, b), cal(x, y, c, d));
    }

    sort(dist, dist + n);

    ll max_suffix[n + 1];
    memset(max_suffix, 0, sizeof(max_suffix));
    for(int i = n - 1; i >= 0; i--) {
	max_suffix[i] = max(max_suffix[i + 1], dist[i].second);
    }

    // ll ans = min(dist[n - 1].first, max_suffix[0]); // get min of only using r1/r2
    ll ans = max_suffix[0]; // using only r2
    for(int i = 0; i < n; i++) {
	ll r1 = dist[i].first;
	ll r2 = max_suffix[i + 1]; // the max of dist.second after i
	ans = min(ans, r1 + r2);
    }

    printf("%lld\n", ans);

    return 0;
}
