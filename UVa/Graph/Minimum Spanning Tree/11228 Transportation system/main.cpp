#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dist(ii &a, ii &b)
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}

#define N 1111
struct UFDS {
	int par[N];
	void init() {
		memset(par, -1, sizeof(par));
	}
		
	int root(int x) {
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}

	void merge(int a, int b) {
		a = root(a);
		b = root(b);

		if(a == b)
			return;

		if(par[a] > par[b])
			swap(a, b);
		par[a] += par[b];
		par[b] = a;
	}
} ufds;

int main()
{
	int ncase;
	scanf("%d", &ncase);
	
	int caseCnt = 1;
	while(ncase--) {
		ufds.init();

		int n, r;
		scanf("%d %d", &n, &r);
		r *= r;

		vector<ii> inp;
		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);

			inp.push_back(ii(x, y));
		}

		vector< pair<int, ii> > d;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				d.push_back(make_pair(dist(inp[i], inp[j]), ii(i, j))); 

		sort(d.begin(), d.end());
		double ans1 = 0, ans2 = 0;
		int ans = 1, earlyTermination = 0;
		for(int i = 0; i < (int)d.size() && earlyTermination < n - 1; i++) {
			int a = d[i].second.first;
			int b = d[i].second.second;
			int dd = d[i].first;
			if(ufds.root(a) == ufds.root(b))
				continue;

			earlyTermination++;
			ufds.merge(a, b);
			if(dd <= r) {
				ans1 += sqrt(dd * 1.0);
			} else {
				ans++;
				ans2 += sqrt(dd * 1.0);
			}
		}

		printf("Case #%d: %d %d %d\n", caseCnt++, ans, (int)round(ans1), (int)round(ans2));
	}

	return 0;
}
