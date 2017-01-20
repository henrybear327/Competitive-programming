#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

#define N 11111
vector<int> g[N];
int deg[N], val[N];
queue<int> q;
void clear(int n)
{
	for(int i = 0; i <= n; i++)
		g[i].clear();
	memset(deg, 0, sizeof(deg));
}

void add_edge(int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int u)
{
	if(deg[u] == 1) {
		deg[u] = 0;
		for(int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i];

			if(deg[v] > 0) {
				deg[v]--;
				dfs(v);
			}
		}
	} else {
		return;
	}
}

bool seen[N];
int cnt = 0;
ll total = 0;
void dfs1(int u)
{
	if(seen[u])
		return;
	seen[u] = true;
	cnt++;
	total += val[u];

	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];

		if(deg[v] > 0) {
			dfs1(v);
		}
	}
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n, m;
		scanf("%d %d", &n, &m);

		clear(n);

		for(int i = 0; i < n; i++) 
			scanf("%d", &val[i]);
		
		for(int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);

			u--;
			v--;

			add_edge(u, v);

			deg[u]++;
			deg[v]++;
		}
		
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			if(deg[i] == 1) // starter
				q.push(i);
		}

		while(q.empty() == false) {
			int u = q.front();
			q.pop();

			dfs(u);
		}
		
		memset(seen, false, sizeof(seen));
		for(int i = 0; i < n; i++) {
			if(deg[i] > 0 && seen[i] == false) {
				cnt = 0;
				total = 0;
				dfs1(i);
				if(cnt % 2 == 1 && cnt > 1)
					sum += total;
			}
		}

		printf("%lld\n", sum);
	}

	return 0;
}
