#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
	ll inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%lld", &inp[i]);
    	
	int upperBound = 1 << n;
	int dp[upperBound] = {0};
	int ans = 0;
	for(int i = 1; i < upperBound; i++) {
	    if(__builtin_popcount(i) < 3) 
		continue;
	    // pick 3, ask for the best ans of the rest
	    for(int a = 0; a < n; a++) {
		if(i & (1 << a)) {
		    for(int b = a + 1; b < n; b++) {
			if(i & (1 << b)) {
			    for(int c = b + 1; c < n; c++) {
				if(i & (1 << c)) {
				    ll x = inp[a], y = inp[b], z = inp[c];
				    if(x + y > z && x + z > y && y + z > x) {
					int mask = i;
					mask ^= (1 << a);
					mask ^= (1 << b);
					mask ^= (1 << c);
					// printf("%d %d\n", i, mask);
					dp[i] = max(dp[i], 1 + dp[mask]);
					ans = max(ans, dp[i]);
				    }
				}
			    }
			}
		    }
		}
	    }
	}	

	printf("%d\n", ans);
    }

    return 0;
}
