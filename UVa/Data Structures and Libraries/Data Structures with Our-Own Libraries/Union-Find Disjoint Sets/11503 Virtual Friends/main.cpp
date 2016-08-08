#include <bits/stdc++.h>

using namespace std;

#define N 100100
struct {
	int par[N];
	void init() {
		fill(par, par + N, -1);
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
	int ncase;
	scanf("%d", &ncase);
	while(ncase--) {
		UFDS.init();

		int n;
		scanf("%d", &n);
		
		int idx = 0;
		map<string, int> list;
		for(int i = 0; i < n; i++) {
			int a, b;
			char inp[1000];

			scanf("%s", inp);
			if(list.find(inp) == list.end()) {
				a = idx;
				list[inp] = idx++;
			} else {
				a = list[inp];
			}

			scanf("%s", inp);
			if(list.find(inp) == list.end()) {
				b = idx;
				list[inp] = idx++;
			} else {
				b = list[inp];
			}

			UFDS.merge(a, b);
			printf("%d\n", -UFDS.par[UFDS.root(a)]);
		}
	}

	return 0;
}
