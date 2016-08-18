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

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n, m;
		scanf("%d %d", &n, &m);

		vector< pair<int, ii> > edge;
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			edge.push_back(make_pair(w, ii(u, v)));
		}

		sort(edge.begin(), edge.end());

		// get MST
		ufds.init();
		vector<int> mst, nmst; // used edge
		int ans1 = 0;
		for(int i = 0; i < (int)edge.size(); i++) {
			int u = edge[i].second.first;
			int v = edge[i].second.second;
			int w = edge[i].first;

			if(ufds.root(u) == ufds.root(v)) {
				nmst.push_back(i);
				continue;
			}

			ufds.merge(u, v);
			mst.push_back(i);
			ans1 += w;
			// printf("%d %d %d\n", i, w, ans1);
		}

		int ans2 = INT_MAX;
		if(n - 1 == m)
			ans2 = ans1;
		else {
			// change one selected edge at a time, and try to replace it with all unselected edge
			for(int i = 0; i < n - 1; i++) {
				int tmp = 0;
				// redo ufds
				ufds.init();
				for(auto j : mst) {
					if(mst[i] == j)
						continue;
					int u = edge[j].second.first;
					int v = edge[j].second.second;
					int w = edge[j].first;
					ufds.merge(u, v);
					tmp += w;
				}
				// printf("tmp %d\n", tmp);

				// try all unused edge
				for(auto j : nmst) {
					int u = edge[j].second.first;
					int v = edge[j].second.second;
					int w = edge[j].first;
					if(ufds.root(u) != ufds.root(v)) {
						ans2 = min(ans2, tmp + w);
					}
				}
			}
		}

		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}
