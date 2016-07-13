#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

bool cmp(ii a, ii b)
{
    if(a.first == b.first)
	return a.second > b.second;
    return b.first > a.first;
}

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

    
    priority_queue< ii, vector<ii>, function<bool(ii, ii)> > pq(cmp);
    pq.push(ii(dp[n] - dp[n - k], n - k));
    
    int l = INT_MAX, r = INT_MAX;
    int offset = 1;
    ll ans = 0;
    for(int i = n - 2 * k; i >= 0; i--) {
	ll tmp = pq.top().first + dp[i + k] - dp[i];
	//printf("i %d %lld %lld %lld\n", i, tmp, pq.top().first, dp[i + k] - dp[i]);

	if(tmp >= ans) {
	    if(l < i + 1)
		continue;
	    if(l == i + 1 && r < pq.top().second)
		continue;
	    ans = tmp;
	    l = i + 1;
	    r = pq.top().second + 1;
	}
	
	pq.push(ii(dp[n - offset] - dp[n - k - offset], n - k - offset));
	offset++;
    }

    printf("%d %d\n", l, r);
    
    return 0;
}
