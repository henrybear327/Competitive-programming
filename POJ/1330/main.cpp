#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define N 10100
#define LOGN 15
vector<int> g[N];

int depth[N], lca[N][15];

void dfs(int u, int p, int d)
{
	if(depth[u] != -1)
		return;
	depth[u] = d;
	lca[u][0] = p;

	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		dfs(v, u, d + 1);
	}
}

void buildLCA(int n, int root)
{
	memset(lca, -1, sizeof(lca));
	memset(depth, -1, sizeof(depth));
	dfs(root, -1, 1); // root is depth 1

	// lca [u][0] is build to its parent after dfs call
	for(int i = 1; i < LOGN; i++) 
		for(int u = 1; u <= n; u++) 
			if(lca[u][i - 1] != -1)
				lca[u][i] = lca[lca[u][i - 1]][i - 1];
}

int queryLCA(int u, int v)
{
	if(depth[u] < depth[v])
		swap(u, v);
	
	// move u v to same depth
	int diff = depth[u] - depth[v];
	for(int i = LOGN - 1; i >= 0; i--) 
		if( (diff >> i) & 1 ) 
			u = lca[u][i];
	
	// check if on same node
	if(u == v)
		return u;
	
	// binary search for answer
	for(int i = LOGN - 1; i >= 0; i--) 
		if(lca[u][i] != lca[v][i]) {
			u = lca[u][i];
			v = lca[v][i];
		}
	return lca[u][0]; // need to go one step forward?
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

		vector<bool> hasParent (n + 1, false);
		for(int i = 0; i < n - 1; i++) {
			int parent, child;
			scanf("%d %d", &parent, &child);
			hasParent[child] = true;
			g[parent].push_back(child);
		}

		int root = -1;
		for(int i = 1; i <= n; i++)
			if(hasParent[i] == false) {
				root = i;
				break;
			}

		buildLCA(n, root);

		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", queryLCA(u, v));
	}

	return 0;
}
