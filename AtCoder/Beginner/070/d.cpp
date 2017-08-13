#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
vector<ii> g[100010];

ll dist[100010];
void dfs(int u, int p)
{
	for(auto next : g[u]) {
		int v = next.first;
		int w = next.second;

		if(v == p)
			continue;
		dist[v] = dist[u] + w;
		dfs(v, u);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d\n", &u, &v, &w);

		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	int q, k;
	scanf("%d %d", &q, &k);
	
	dist[k] = 0;
	dfs(k, -1);

	for(int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		printf("%lld\n", dist[u] + dist[v]);
	}

	return 0;
}
