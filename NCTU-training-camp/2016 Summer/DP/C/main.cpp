#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    ll dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
	dp[i] = dp[i - 1] + inp[i - 1];

    ii mx = ii(dp[n] - dp[n - k], n - k);
    
    int offset = 1;
    ll ans = 0;
    int l, r;
    for(int i = n - 2 * k; i >= 0; i--) {
	ll tmp = dp[i + k] - dp[i] + mx.first;
	
	if(tmp >= ans) {
	    ans = tmp;
	    l = i + 1;
	    r = mx.second + 1;
	}
	mx = (dp[n - offset] - dp[n - k - offset]) >= mx.first ? 
	    ii(dp[n - offset] - dp[n - k - offset], n - k - offset) : mx;
	offset++;

    }

    printf("%d %d\n", l, r);
    
    return 0;
}
