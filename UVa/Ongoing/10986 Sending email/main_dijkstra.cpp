#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 22222;
vector<ii> g[N];

int main()
{
	int ncase;
	scanf("%d", &ncase);
	
	int caseCnt = 1;
	while(ncase--) {
		printf("Case #%d: ", caseCnt++);

		int n, m, s, t;
		scanf("%d %d %d %d", &n, &m, &s, &t);
		
		for(int i = 0; i < n; i++)
			g[i].clear();

		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			g[u].push_back(ii(v, w));
			g[v].push_back(ii(u, w));
		}

		// s->t
		ll d[n];
		fill(d, d + n, INT_MAX);

		d[s] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, s));

		while(pq.empty() == false) {
			ii cur = pq.top();
			pq.pop();

			int u = cur.second, w = cur.first;
			if(d[u] < w)
				continue;

			for(auto i : g[u]) {
				int v = i.first, ww = i.second;
				if(w + ww < d[v]) {
					d[v] = w + ww;
					pq.push(ii(d[v], v));
				}
			}
		}
		
		if(d[t] == INT_MAX)
			printf("unreachable\n");
		else
			printf("%lld\n", d[t]);
	}

	return 0;
}
