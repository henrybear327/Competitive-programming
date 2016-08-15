#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;

#define N 200100
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

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) == 2 && (m || n)) {
		ufds.init();

		int sum = 0;
		vector< pair<int, ii> > inp;
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			sum += w;
			inp.push_back(make_pair(w, ii(u, v)));
		}
		sort(inp.begin(), inp.end());
		
		int early = 0, tot = 0;
		for(int i = 0; i < (int)inp.size() && early < n - 1; i++) {
			int w = inp[i].first;
			int u = inp[i].second.first;
			int v = inp[i].second.second;

			if(ufds.root(u) == ufds.root(v))
				continue;

			early++;
			ufds.merge(u, v);
			tot += w;
		}
		printf("%d\n", sum - tot);
	}

	return 0;
}
