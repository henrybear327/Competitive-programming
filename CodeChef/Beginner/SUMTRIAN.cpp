#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
	int n;
	scanf("%d", &n);
	
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i + 1; j++) 
			scanf("%d", &dp[i][j]);
		
		for(int j = 0; j < i + 1; j++) 
			if(i - 1 >= 0)
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][(j - 1 >= 0 ? j - 1 : j)]);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, dp[n - 1][i]);
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
