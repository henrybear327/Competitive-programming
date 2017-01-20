#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
typedef pair<int , ii> iii;

int n, m, q;
#define N 22222
vector<iii> edges;
void clear()
{
	edges.clear();
}

ll sum;
struct UFDS {
	ll par[N];
	ll total[N];

	void init()
	{
		memset(par, -1, sizeof(par));
		memset(total, 0, sizeof(total));
	}

	int root(int x)
	{
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}

	void merge(int x, int y)
	{
		x = root(x);
		y = root(y);

		if(x == y)
			return;

		if(par[x] > par[y])
			swap(x, y);

		sum += 2 * -par[x] * -par[y];

		total[x] += total[y];
		total[x] += 2 * -par[x] * -par[y]; 

		par[x] += par[y];
		par[y] = x;
	}
} uf;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		scanf("%d %d %d", &n, &m, &q);
		clear();
		uf.init();

		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			edges.push_back(iii(w, ii(u, v)));
		}

		sort(edges.begin(), edges.end());
		
		vector<ii> query;
		for(int i = 0; i < q; i++) {
			int num;
			scanf("%d", &num);

			query.push_back(ii(num, i));
		}

		sort(query.begin(), query.end());
		
		int idx = 0;
		sum = 0;
		vector<ii> ans;
		for(auto i : query) {
			while(idx < (int)edges.size() && edges[idx].first <= i.first) {
				uf.merge(edges[idx].second.first, edges[idx].second.second);
				idx++;
			}
			
			ans.push_back(ii(i.second, sum));
		}

		sort(ans.begin(), ans.end());

		for(auto i : ans)
			printf("%lld\n", i.second);
	}

	return 0;
}
