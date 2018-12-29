#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 300010;
int gas[N];
vector<ii> g[N];

ll ans = 0;

// tree dfs
ll dfs(int u, int p)
{
	ll bestPathSoFar = gas[u]; // best path value rooted at u
	ans = max(bestPathSoFar, ans);

	for (auto node : g[u]) {
		int v = node.first;
		int w = node.second;

		if (v == p)
			continue;

		ll childPath = dfs(v, u); // best path value rooted at v

		// combine 2 paths and attempt to update
		// y .... u --(w)-- v .... x
		ans = max(ans, bestPathSoFar + childPath - w);
		// attempt to update the best value rooted at u
		bestPathSoFar = max(bestPathSoFar, childPath + gas[u] - w);
	}

	return bestPathSoFar;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &gas[i]);

	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		u--;
		v--;

		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	dfs(0, -1);

	printf("%lld\n", ans);

	return 0;
}
