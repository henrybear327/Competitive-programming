#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

#define N 200010
vector<ii> g[N];

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
		int ans = 0;
		bool used[n];
		memset(used, false, sizeof(used));

		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, 0)); // push (0, origin)
		while(!pq.empty()) {
			ii cur = pq.top(); 
			pq.pop();
			
			int u = cur.second;
			if(used[u])
				continue;
			ans += cur.first;
			used[u] = true;
			
			for(int i = 0; i < (int)g[u].size(); i++) {
				int v = g[u][i].first, w = g[u][i].second;
				if(used[v] == false)
					pq.push(ii(w, v));
			}
		}

		printf("%d\n", sum - ans);
	}

	return 0;
}
