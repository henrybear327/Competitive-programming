#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define N 10100
vector<int> g[N];

int lca[N][15], depth[N];

bool seen[N];
void dfs(int u, int p, int d)
{
	if(seen[u])
		return;
	seen[u] = true;

	lca[u][0] = p;
	depth[u] = d;

	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];

		if(v == p)
			continue;
		dfs(v, u, d + 1);
	}
}

void computeLCA(int n, int root)
{
	// build lca[i][0]; // 2^0 step
	memset(seen, false, sizeof(seen));
	memset(depth, 0, sizeof(depth));
	dfs(root, -1, 0);

	// build lca[i][all the rest]
	for(int i = 1; i < 15; i++) {
		for(int u = 1; u <= n; u++) {
			if(lca[u][i - 1] != -1)
				lca[u][i] = lca[lca[u][i - 1]][i - 1];
		}
	}
}

int query(int x, int y)
{
	if(depth[x] < depth[y]) // let x be deeper
		swap(x, y);

	// move to same depth
	int depthDiff = depth[x] - depth[y];
	for(int i = 0; i < 15; i++) {
		if(depthDiff & (1 << i)) {
			x = lca[x][i];
		}
	}

	// check x == y
	if(x == y)
		return x;

	// move up till same
	for(int i = 15 - 1; i >= 0; i--) {
		if(lca[x][i] != lca[y][i]) {
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++) 
			g[i].clear();

		// build
		memset(lca, -1, sizeof(lca));
		for(int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);

			lca[v][0] = u;
			g[u].push_back(v);
		}

		int root;
		for(int i = 1; i <= n; i++)
			if(lca[i][0] == -1)
				root = i;

		// precompute LCA
		computeLCA(n, root);

		// query
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y));
	}

	return 0;
}
