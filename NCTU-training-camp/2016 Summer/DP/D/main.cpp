#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// bitmask DP
// Bitmask DP basically needs the constraints of n, m, ... less than 20
// 2^20 = 1048576 = 10^6

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    ll val[n];
    for(int i = 0; i < n; i++)
	scanf("%lld", &val[i]);
    ll bonus[n][n];
    memset(bonus, 0, sizeof(bonus));
    for(int i = 0; i < k; i++) {
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);

	bonus[u - 1][v - 1] = w;
    }
    
    int upperLimit = 1 << n;
    ll dp[upperLimit][n];
    memset(dp, 0, sizeof(dp));

    // list all combination
    ll ans = 0;
    for(int s = 1; s < upperLimit; s++) {
	for(int v = 0; v < n; v++) {
	    // check if pos u is in set s
	    if( (s & (1 << v)) == 0 ) 
		continue;

	    // check set size <= m
	    int cnt = 0;
	    for(int u = 0; u < n; u++) {
		if( (s & (1 << u)) != 0)
		    cnt++;
	    }
	    // if oversized, ignore
	    
	    // if m = 1 and we calculate the result using m = 2
	    // we might get "better" result for selecting only 1 plate because of the accumulating property of this algorithm
	    if(cnt > m)
		continue;
	    
	    // calculate dp
	    // from the prev state to current state (e.g. 0110 to 0111)
	    // because prev state 0110 is already calculated, so the optimal solution till now (0111)
	    // is prev_best + val[v] + bonus[u][v]
	    for(int u = 0; u < n; u++) {
		if( (s & (1 << u) ) == 0 )
		    continue;

		dp[s][v] = max(dp[s][v], dp[s ^ (1 << v)][u] + val[v] + bonus[u][v]);
	    }
	    
	    if(cnt == m)
		ans = max(ans, dp[s][v]);
	}
    }

    printf("%lld\n", ans);

    return 0;
}
