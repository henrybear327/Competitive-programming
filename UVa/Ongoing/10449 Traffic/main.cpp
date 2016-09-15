#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int cube(int val)
{
	return val * val * val;
}

int main()
{
	int n, caseCnt = 1;
	while(scanf("%d", &n) == 1) {
		int val[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &val[i]);

		int r;
		scanf("%d", &r);
		vector<ii> edge;
		for(int i = 0; i < r; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;

			edge.push_back(ii(u, v));
		}

		// bellman ford
		vector<ll> d(n, INT_MAX);
		if(n > 0)
			d[0] = 0;
		for(int i = 0; i < n; i++) {
			bool hasChange = false;
			for(int j = 0; j < (int)edge.size(); j++) {
				int u = edge[j].first, v = edge[j].second, w = cube(val[v] - val[u]);
				if(d[u] != INT_MAX && d[u] + w < d[v]) {// the first condition is curcial!
					d[v] = d[u] + w;
					hasChange = true;

					if(i == n - 1) {
						d[v] = INT_MIN;
					}
				}
			}
		
			if(hasChange == false)
				break;
		}

		int q;
		scanf("%d", &q);
		
		printf("Set #%d\n", caseCnt++);
		for(int i = 0; i < q; i++) {
			int v;
			scanf("%d", &v);
			v--;

			if(d[v] < 3 || d[v] == INT_MAX)
				printf("?\n");
			else
				printf("%lld\n", d[v]); 
		}
	}

	return 0;
}
