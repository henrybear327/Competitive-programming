#include <bits/stdc++.h>

using namespace std;

struct {
	int par[26];
	void init() {
		fill(par, par + 26, -1);
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
} UFDS;

int main()
{	
	int n;
	while(scanf("%d", &n) == 1) {
		UFDS.init();

		int k;
		scanf("%d", &k);

		char inp[100];
		scanf("%s", inp);

		int degree[26] = {0}, usage = 0;
		bool used[26] = {false};
		vector<int> g[26];
		for(int i = 0; i < k; i++) {
			char tmp[10];
			scanf("%s", tmp);

			int u = tmp[0] - 'A', v = tmp[1] - 'A';
			g[u].push_back(v);
			g[v].push_back(u);
			degree[u]++;
			degree[v]++;
			if(used[u] == false)
				usage++;
			if(used[v] == false)
				usage++;
			used[u] = used[v] = true;

			UFDS.merge(u, v);
		}

		if(n == (int)strlen(inp)) { // really, really dude?
			printf("WAKE UP IN, 0, YEARS\n");
			continue;
		}

		if(usage != n) { // really, really dude? You missed this case?
			printf("THIS BRAIN NEVER WAKES UP\n");
			continue;
		}

		bool active[26] = {false};
		int len = strlen(inp);
		for(int i = 0; i < len; i++) 
			active[inp[i] - 'A'] = true;

		vector<int> group[26];
		for(int i = 0; i < 26; i++) {
			if(used[i] == true) {
				group[UFDS.root(i)].push_back(i);
			}
		}

		bool ok = true;
		int ans = 0;
		for(int i = 0; i < 26 && ok; i++) {
			if(group[i].size() > 0) {
				for(int j = 0; j < (int)group[i].size(); j++) {
					int v = group[i][j];
					if(degree[v] < 3 && active[v] == false) {
						ok = false;
						break;
					}
				}

				if(ok) {
					int cur = 0, gsize = 0;
					for(int j = 0; j < (int)group[i].size(); j++) {
						int v = group[i][j];
						if(active[v] == true)
							gsize++;
					}
					int prev = gsize;
					while(gsize < (int)group[i].size()) {
						cur++;
						vector<int> delay;
						for(int j = 0; j < (int)group[i].size(); j++) {
							int v = group[i][j];
							if(active[v] == false) {
								int tmp = 0;
								for(auto k : g[v]) {
									if(active[k] == true)
										tmp++;
								}
								if(tmp >= 3) {
									gsize++;
									delay.push_back(v);
								}
							}
						}
						for(auto j : delay)
							active[j] = true;

						if(prev == gsize) {
							ok = false;
							break;
						} else {
							prev = gsize;
						}
					}

					ans = max(ans, cur);
				}	
			}
		}

		if(ok) {
			printf("WAKE UP IN, %d, YEARS\n", ans);
		} else {
			printf("THIS BRAIN NEVER WAKES UP\n");
		}
	}

	return 0;
}
