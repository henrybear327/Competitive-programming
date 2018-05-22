#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

ll gcd(ll x, ll y)
{
    return x == 0 ? y : gcd(y % x, x);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    pair<ll, ll> inp[2000];
    for(int i = 0; i < n; i++) 
	scanf("%lld %lld", &inp[i].first, &inp[i].second);

    map< pair<ll, pair <ll, ll> >, int > slope;
    for(int i = 0; i < n; i++) {
	for(int j = i + 1; j < n; j++) {
	    ll dx = inp[j].first - inp[i].first;
	    ll dy = inp[j].second - inp[i].second;
	    // printf("%d %d %lld %lld\n", i, j, dx, dy);

	    if((dx < 0 && dy > 0)) {
		dx = -dx;
		dy = -dy;
	    } else if(dx == 0 && dy < 0)
		dy = -dy;
	    else if(dy == 0 && dx < 0)
		dx = -dx;

	    slope[make_pair(dx * dx + dy * dy, make_pair(dx / gcd(dx, dy), dy / gcd(dx, dy)))]++;
	}
    }
    
    ll ans = 0;
    for(auto i : slope) {
	//printf("%lld, %lld, %lld, %d\n", i.first.first, i.first.second.first, i.first.second.second, i.second);

	ll tmp = i.second;
	ans += tmp * (tmp - 1) / 2;
    }
    printf("%lld\n", ans / 2); 
    /*
	a, b will be counted
	c, d will also be counted
	So, ans / 2!
	  ----   <-a
	 /   /
	/   /
	----     <-b
    */

    return 0;
}