#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define N 25000
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
	while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
		vector< pair<int, ii> > inp;
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			inp.push_back( make_pair(w, ii(u, v)));
		}

		sort(inp.begin(), inp.end());
		
		ufds.init();
		vector<int> ans;
		for(int i = 0; i < (int)inp.size(); i++) {
			int u = inp[i].second.first;
			int v = inp[i].second.second;
			int w = inp[i].first;

			if(ufds.root(u) == ufds.root(v)) {
				ans.push_back(w);
				continue;
			}

			ufds.merge(u, v);
		}

		sort(ans.begin(), ans.end());

		if(ans.size() > 0) {
			for(int i = 0; i < (int) ans.size(); i++)
				printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
		} else {
			printf("forest\n");
		}
	}

	return 0;
}
