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
    ll n, h, k;
    scanf("%lld %lld %lld", &n, &h, &k);

    ll inp[n];
    for(int i = 0; i < n; i++) 
	scanf("%lld", &inp[i]);
    
    ll ans = 0, cur = 0;
    for(int i = 0; i < n; i++) {
	if(cur + inp[i] <= h) {
	    cur += inp[i];
	} else {
	    cur -= k;
	    if(cur < 0)
		cur = 0;
	    ans++;
	    while(cur + inp[i] > h) {
		ll x = (cur + inp[i] - h) / k;
		if((cur + inp[i] - h) % k)
		    x++;
		ans += x;
		cur -= x * k;
		if(cur < 0)
		    cur = 0;
		/*
		cur -= k;
		if(cur < 0)
		    cur = 0;
		ans++;
		*/
	    }
	    cur += inp[i];
	}
    }	    
    while(cur > 0) {
	cur -= k;
	ans++;
    }

    printf("%lld\n", ans);

    return 0;
}
