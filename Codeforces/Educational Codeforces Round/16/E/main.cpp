#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int)1e7 + 10;
ll dp[N];

int main()
{
	int n; 
	ll x, y;
	scanf("%d %lld %lld", &n, &x, &y);

	for(int i = 1; i <= n; i++) {
		dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + y + x * (i % 2));
		/*
		if(i % 2 == 0) {
			dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
		} else {
			dp[i] = dp[i - 1] + x;
		}

		if(__builtin_popcount(i) == 1) {
			for(int j = i - 1; j > i / 2; j--) {
				dp[j] = min(dp[j], dp[j + 1] + x);
			}
		}
		*/
	}

	printf("%lld\n", dp[n]);

	return 0;
}
