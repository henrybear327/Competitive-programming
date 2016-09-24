#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	int n;
	scanf("%d", &n);
	
	int inp[n];
	int mx = 0, idx = -1;
	for(int i = 0; i < n; i++) { 
	    scanf("%d", &inp[i]);
	    if(mx <= inp[i]) {
		mx = inp[i];
		idx = i;
	    }
	}
	
	int l = 0;
	ll ans = 0;

	for(int i = 1; i < idx; i++) {
	    if(inp[i] < inp[l])
		ans += (inp[l] - inp[i]);
	    else 
		l = i;
	}

	l = n - 1;
	for(int i = n - 2; i >= idx; i--) {
	    if(inp[i] < inp[l])
		ans += (inp[l] - inp[i]);
	    else
		l = i;
	}

	printf("%lld\n", ans);
    }

    return 0;
}