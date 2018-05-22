#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

inline ll gcd(ll x, ll y)
{
    return x == 0 ? y : gcd(y % x, x);
}
pair <int, int> slope[2000 * 2000];

int main()
{
    int n;
    scanf("%d", &n);
    
    pair<ll, ll> inp[2000];
    for(int i = 0; i < n; i++) 
	scanf("%lld %lld", &inp[i].first, &inp[i].second);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
	for(int j = i + 1; j < n; j++) {
	    ll dx = inp[j].first - inp[i].first;
	    ll dy = inp[j].second - inp[i].second;
	    // printf("%d %d %lld %lld\n", i, j, dx, dy);

	    if((dx < 0 && dy > 0)) {
		dx = -dx;
		dy = -dy;
	    } else if(dx < 0 && dy < 0) {// bitch!
		dx = -dx;
		dy = -dy;
	    } else if(dx == 0 && dy < 0)
		dy = -dy;
	    else if(dy == 0 && dx < 0)
		dx = -dx;

	    slope[cnt++] = make_pair(dx, dy); // only the dx, dy can distinguish the slope type!
	}
    }
	
    sort(slope, slope + cnt);
    int prev = 0;
    ll ans = 0;
    for(int i = 1; i <= cnt; i++) {
	//printf("%lld, %lld %lld\n", slope[i].first, slope[i].second.first, slope[i].second.second);
	if(i == cnt || slope[i] != slope[i - 1]) {
	    ll tmp = i - prev;
	    ans += tmp * (tmp - 1) / 2;
	    prev = i;
	}
    }
    /*
    ll ans = 0;
    for(auto i : slope) {
	//printf("%lld, %lld, %lld, %d\n", i.first.first, i.first.second.first, i.first.second.second, i.second);

	ll tmp = i.second;
	ans += tmp * (tmp - 1) / 2;
    }
    */
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
