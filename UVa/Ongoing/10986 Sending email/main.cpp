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
		vector<ll> d(n, INT_MAX);
		d[s] = 0;

		queue<int> q;
		vector<bool> inqueue(n, false);
		vector<int> cnt(n, 0);
		q.push(s);
		inqueue[s] = true;
		cnt[s]++;

		while(q.empty() == false) {
			int u = q.front();
			q.pop();
			inqueue[u] = false;

			for(auto i : g[u]) {
				int v = i.first, w = i.second;
				if(d[u] + w < d[v]) {
					d[v] = d[u] + w;
					if(inqueue[v] == false) {
						q.push(v);
						inqueue[v] = true;
						cnt[v]++;

						if(cnt[v] == n) {
							// loop!
						}
					}
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
