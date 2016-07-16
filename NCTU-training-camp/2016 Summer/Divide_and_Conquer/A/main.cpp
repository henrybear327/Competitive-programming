#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    ii inp[100010];
    for(int i = 0; i < n; i++) {
	ll a, b;
	scanf("%lld %lld", &a, &b);

	inp[i] = ii(a, b);
    }
    sort(inp, inp + n);
    
    int j = 0;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
	if(i == j) {
	    sum += inp[i].second;
	} else {
	    if(inp[i].first - inp[j].first >= k) {
		while(j < i && inp[i].first - inp[j].first >= k) {
		    sum -= inp[j].second;
		    j++;
		}
	    }
	    sum += inp[i].second;
	}

	ans = max(ans, sum);
    }

    printf("%lld\n", ans);
	
    return 0;
}
