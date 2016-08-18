#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define N 111
struct UFDS {
	int par[N];
	void init() {
		memset(par, -1, sizeof(par));
	}
	
	int root(int x) {
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}

	void merge(int x, int y) {
		x = root(x);
		y = root(y);

		if(x == y)
			return;

		if(par[x] > par[y])
			swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}
} ufds;

vector< ii > g[N];
int mx;
bool dfs(int u, int t, int p) 
{
	if(u == t)
		return true;

	for(auto v : g[u]) {
		if(v.first == p)
			continue;
		if(dfs(v.first, t, u)) {
			mx = max(mx, v.second);
			return true;
		}
	}

	return false;
}

int main()
{
	int n, m, q, caseCnt = 1;
	bool first = true;
	while(scanf("%d %d %d", &n, &m, &q) == 3 && (n || m || q)) {
		if(first) {
			first = !first;
		} else {
			printf("\n");
		}
		printf("Case #%d\n", caseCnt++);

		for(int i = 0; i < N; i++)
			g[i].clear();

		vector< pair<int, ii> > inp;
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			inp.push_back(make_pair(w, ii(u, v)));
		}

		sort(inp.begin(), inp.end());
	
		ufds.init();

		for(int i = 0; i < (int)inp.size(); i++) {
			int u = inp[i].second.first;
			int v = inp[i].second.second;
			int w = inp[i].first;

			if(ufds.root(u) == ufds.root(v))
				continue;

			ufds.merge(u, v);
			g[u].push_back(ii(v, w));
			g[v].push_back(ii(u, w));
		}
		
		for(int i = 0; i < q; i++) {
			int u, v;
			scanf("%d %d", &u, &v);

			if(ufds.root(u) == ufds.root(v)) {
				mx = 0;
				dfs(u, v, -1);
				printf("%d\n", mx);
			} else {
				printf("no path\n");
			}
		}
	}

	return 0;
}
