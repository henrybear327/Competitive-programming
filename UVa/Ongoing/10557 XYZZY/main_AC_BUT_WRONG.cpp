#include <bits/stdc++.h>

// wrong version but AC

// the result doesn't match the problem statement! (path shouldn't have a moment <= 0)

using namespace std;

#define N 111
vector<int> g[N];
int n, energy[N], seen[N][N];

bool spfa()
{
	if(seen[1][n] == false)
		return false;

	queue<int> q;
	q.push(1);
	vector<int> inqueue(n + 1, false);
	inqueue[1] = true;
	vector<int> cnt(n + 1, 0);
	cnt[1]++;
	
	vector<int> dist(n + 1, -1);

	dist[1] = 100;
	while(q.empty() == false) {
		/*
		for(int i = 1; i <= n; i++)
			printf("%d%c", dist[i], i == n ? '\n' : ' ');
		*/

		int u = q.front();
		q.pop();
		inqueue[u] = false;

		if(dist[u] == INT_MAX)
			continue;

		for(auto v : g[u]) {
			int w = energy[v];
			if(dist[u] + w > dist[v]) {
				dist[v] = dist[u] + w;
				if(inqueue[v] == false) {
					inqueue[v] = true;
					cnt[v]++;
					q.push(v);

					if(cnt[v] >= n) {
						if(seen[v][n])
							return true;
						dist[v] = INT_MAX;
					}
				}
			}
		}
	}

	return dist[n] > 0;
}

void dfs(int u, int row)
{
	if(seen[row][u])
		return;
	seen[row][u] = true;
	
	for(auto v : g[u]) 
		dfs(v, row);
}

int main()
{
	while(scanf("%d", &n) == 1 && n != -1) {
		// clear
		for(int i = 1; i <= n; i++)
			g[i].clear();
		
		// build graph
		for(int i = 1; i <= n; i++) {
			scanf("%d", &energy[i]);

			int m;
			scanf("%d", &m);

			for(int j = 0; j < m; j++) {
				int v;
				scanf("%d", &v);
				g[i].push_back(v);
			}
		}

		// solve
		memset(seen, false, sizeof(seen));
		for(int i = 1; i <= n; i++) {
			dfs(i, i);
		}
		bool ok = spfa();

		// result
		printf("%s\n", ok ? "winnable" : "hopeless");	
	}

	return 0;
}
