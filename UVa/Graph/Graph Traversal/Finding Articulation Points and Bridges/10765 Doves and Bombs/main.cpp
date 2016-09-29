#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 11111
vector<int> g[N];
int dfsTime[N], dfsLow[N], timer, root;
int articulationPoint[N];

typedef pair<int, int> ii;

void dfs(int u, int p) {
	// printf("u %d p %d\n", u, p);
	dfsTime[u] = dfsLow[u] = timer++;

	int child = 0;
	for(auto v : g[u]) {
		if(v == p)
			continue;

		if(dfsTime[v] == 0) {
			child++;
			// printf("v %d\n", v);
			dfs(v, u);
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);

			if(dfsTime[u] <= dfsLow[v] && u != root)
				articulationPoint[u]++;
			if(root == u && child >= 2)
				articulationPoint[root]++;
			// printf("pt %d %d\n", u, articulationPoint[u]);
		} else {
			dfsLow[u] = min(dfsLow[u], dfsTime[v]);
		}
	}
}

bool cmp(ii a, ii b)
{
	if(a.second == b.second) 
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
		// init
		for(int i = 0; i < n; i++)
			g[i].clear();

		// build graph
		int u, v;
		while(scanf("%d %d", &u, &v) == 2 && (u != -1 && v != -1)) {
			g[u].push_back(v);
			g[v].push_back(u);
		}

		// find articulation point
		memset(dfsTime, 0, sizeof(dfsTime));
		memset(dfsLow, 0, sizeof(dfsLow));
		memset(articulationPoint, 0, sizeof(articulationPoint));
		for(int i = 0; i < n; i++) {
			if(dfsTime[i] == 0) {
				timer = 1;
				root = i;
				dfs(i, -1);
			}
		}

		vector<ii> res;
		for(int u = 0; u < n; u++) {
			res.push_back(ii(u, articulationPoint[u] + 1));
		}
		sort(res.begin(), res.end(), cmp);
		for(int i = 0; i < m; i++)
			printf("%d %d\n", res[i].first, res[i].second);
		printf("\n");
	}

	return 0;
}
