#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[33][33];
ll comb(int a, int b)
{
	if(a == 1)
		return 1;
	if(b == 0 || a == b)
		return 1;
	
	if(dp[a][b] != 0)
		return dp[a][b];
	return dp[a][b] = comb(a - 1, b - 1) + comb(a - 1, b);
}

int main()
{
	memset(dp, 0, sizeof(dp));

	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);

	ll ans = 0;
	for(int i = 4; i <= a && c - i >= 1; i++) {
		if(c - i > b)
			continue;
		ans += comb(a, i) * comb(b, c - i);
	}
	printf("%lld\n", ans);

	return 0;
}
