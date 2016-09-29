#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

#define N 5555
vector<int> g[N];

int cnt, root, dfsTime[N], dfsLow[N], timer;
stack<int> s;
int group[N];
bool in[N];
void dfs(int u, int p)
{
	s.push(u);
	in[u] = true;

	dfsTime[u] = dfsLow[u] = timer++;

	int prev = -1;
	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];

		if(v == p || v == prev)
			continue;
		prev = v;

		if(dfsTime[v] == 0) {
			dfs(v, u);
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else {
			if(in[u]) // gain speed
				dfsLow[u] = min(dfsLow[u], dfsTime[v]);
		}
	}

	if(dfsTime[u] == dfsLow[u]) { //当low[u]==dfn[u]时就说明找到了一个连通的块
		cnt++;
		while(true) {
			int v = s.top();
			s.pop();
			in[v] = false;

			group[v] = cnt;
			if(v == u)
				break;
		}
	}

	// printf("%d %d\n", u, cnt);
}

int seen[N][N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	// build
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		if(seen[u][v]) // bull shit
			continue;
		g[u].push_back(v);
		g[v].push_back(u);
		seen[u][v] = seen[v][u] = true;
	}

	// cnt BCC
	memset(dfsTime, 0, sizeof(dfsTime));
	memset(dfsLow, 0, sizeof(dfsLow));
	memset(group, 0, sizeof(group));
	memset(in, false, sizeof(in));
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(dfsTime[i] == 0) {
			root = i;
			timer = 1;
			dfs(i, -1);
		}
	}

	// get degree
	int deg[n + 1];
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (int)g[i].size(); j++) {
			int v = g[i][j];
			if(group[i] != group[v])
				deg[group[i]]++;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(deg[i] == 1)
			ans++;

	printf("%d\n", (ans + 1) / 2);

	return 0;
}

