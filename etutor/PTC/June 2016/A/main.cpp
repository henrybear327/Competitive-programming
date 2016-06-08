#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define N 60010

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n) {
	/*
	max( station[a] + station[b] + pre[b] - pre[a],
	     station[a] + station[b] + (total - (pre[b] - pre[a])) )

	= max( (station[a] - pre[a]) + (station[b] + pre[b]),
    	       (station[a] + pre[a]) + (station[b] - pre[b]) + total )
	*/
    
	ll station[n], edge[n], total = 0;
	for(int i = 0; i < n; i++) {
	    scanf("%lld %lld", &station[i], &edge[(i + 1) % n]);
	    total += edge[(i + 1) % n];
	}

	ll pre[n];
	pre[0] = 0;
	for(int i = 1; i < n; i++) {
	    pre[i] = pre[i - 1] + edge[i];
	}

	ll plus[n], minus[n];
	for(int i = 0; i < n; i++)
	    plus[i] = station[i] + pre[i];
	for(int i = 0; i < n; i++)
	    minus[i] = station[i] - pre[i];
	
	ll maxPlus[n], maxMinus[n];
	maxPlus[n - 1] = plus[n - 1];
	maxMinus[n - 1] = minus[n - 1];
	for(int i = n - 2; i >= 0; i--)
	    maxPlus[i] = max(maxPlus[i + 1], plus[i]);
	for(int i = n - 2; i >= 0; i--)
	    maxMinus[i] = max(maxMinus[i + 1], minus[i]);
	
	ll ans = 0;
	for(int i = 0; i < n - 1; i++) {
	    ans = max(ans, max(minus[i] + maxPlus[i + 1], plus[i] + maxMinus[i + 1] + total));
	}
	printf("%lld\n", ans);
    }

    return 0;
}
