#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define N 100010
vector<ii> g[N];
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	bool flour[n + 1];
	memset(flour, false, sizeof(flour));
	for(int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);

		flour[tmp] = true;;
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < n + 1; i++) {
		if(g[i].size() == 0)
			continue;
		if(flour[i] == false)
			continue;

		for(int j = 0; j < (int)g[i].size(); j++) {
			int v = g[i][j].first;

			if(flour[v] == true)
				continue;
			ans = min(ans, g[i][j].second);
		}
	}

	printf("%d\n", ans == INT_MAX ? -1 : ans);
	
    return 0;
}
