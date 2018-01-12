#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d", &n);

	if(n == 1) {
		printf("1\n0\n");
		return 0;
	}

	int dp[n];
	int par[n];
	int deg[n];
	memset(par, -1, sizeof(par));
	memset(dp, 0, sizeof(dp));

	queue<int> q;
	for(int p = 0; p < n; p++) {
		int k;
		scanf("%d", &k);
		if(k == 0)
			q.push(p);

		deg[p] = k;

		for(int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			child--;
			par[child] = p;
		}
	}	

	while(q.size() > 0) {
		int cur = q.front();
		q.pop();

		if(par[cur] != -1) {
			dp[par[cur]] = max(dp[par[cur]], dp[cur] + 1);
			deg[par[cur]]--;
			if(deg[par[cur]] == 0)
				q.push(par[cur]);
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(par[i] == -1)
			printf("%d\n", i + 1);
		ans += dp[i];
	}
	printf("%lld\n", ans);

	return 0;
}
