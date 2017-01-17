#include <bits/stdc++.h>

using namespace std;

int n, s, t, c;
int g[111][111];

bool seen[111];
int dfs(int u, int v, int c)
{
	seen[u] = true;
	if(u == v)
		return c;
	for(int i = 1; i <= n; i++) {
		if(g[u][i] > 0 && seen[i] == false) {
			int res = 0;
			if( (res = dfs(i, v, min(c, g[u][i]))) > 0) {
				g[u][i] -= res;
				g[i][u] += res;
				return res;
			}
		}
	}

	return 0;
}

int maxflow()
{
	int res = 0, tmp = 0;
	memset(seen, false, sizeof(seen));
	while(( tmp = dfs(s, t, INT_MAX) ) > 0) {
		res += tmp;
		memset(seen, false, sizeof(seen));
	}
	return res;
}

int main()
{
	int id = 1;
	while(scanf("%d", &n) == 1 && n) {
		scanf("%d %d %d", &s, &t, &c);
		
		memset(g, 0, sizeof(g));
		for(int i = 0; i < c; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			g[u][v] += w;
			g[v][u] += w;
		}
		
		printf("Network %d\n", id++);
		printf("The bandwidth is %d.\n\n", maxflow());
	}

	return 0;
}
