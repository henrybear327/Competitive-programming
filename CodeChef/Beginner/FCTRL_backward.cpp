#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int dp[13];

void pre()
{
	ll base = 5;
	for(int i = 1; i <= 12; i++) {
		// printf("%d %lld\n", i, base);
		dp[i] = base;
		base *= 5;
	}
}

void solve()
{
	int n;
	scanf("%d", &n);

	ll ans = 0;
	ll accum = 0;
	for(int i = 12; i >= 1; i--) {
		ll cnt = n / dp[i];
		
		ans += i * cnt - accum;

		accum += cnt;
	}
	
	printf("%lld\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	pre();
	
	while(ncase--) {
		solve();
	}

	return 0;
}
