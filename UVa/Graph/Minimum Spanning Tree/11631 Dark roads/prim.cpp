#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

#define N 200010
vector<ii> g[N];

struct UFDS 
{
	int par[N];
	void init(int n) {
		memset(par, -1, sizeof(int) * n);
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
} uf;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
		// clear
		for(int i = 0; i <= n; i++)
			g[i].clear();
		
		// build
		int sum = 0;
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			g[u].push_back(ii(v, w));
			g[v].push_back(ii(u, w));

			sum += w;
		}

		// prim
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, 0)); // push (0, origin)
		
		uf.init(n + 1); // init union find
		int ans = 0, earlyTermination = 0;
		while(!pq.empty()) {
			ii cur = pq.top(); 
			pq.pop();
			
			int u = cur.second;
			if(u != 0 && (uf.root(0) == uf.root(u))) // check loop
				continue;
			uf.merge(0, u); 
			ans += cur.first;
			earlyTermination++;
			if(earlyTermination == n) // because of the first node is dummy node
				break;
			
			for(int i = 0; i < (int)g[u].size(); i++) {
				int v = g[u][i].first, w = g[u][i].second;

				if(uf.root(0) != uf.root(v)) {
					pq.push(ii(w, v));
				}
			}
		}

		printf("%d\n", sum - ans);
	}

	return 0;
}
