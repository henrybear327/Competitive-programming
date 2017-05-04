#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 111;
const int MAX = 0x3f3f3f3f;
typedef pair<int, int> ii;

struct Edge {
	int to, cost;

	Edge(int a, int b)
	{
		to = a;
		cost = b;
	}
};

vector<Edge> g[MAX_N];

int n, e, t, m;
int dist[MAX_N];
void dijkstra(int s)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;

	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));

	while(pq.size() > 0) {
		ii cur = pq.top();
		pq.pop();
		int v = cur.second;
		int d = cur.first;
		
		if(dist[v] < d)
			continue;

		for(auto edge : g[v]) {
			int newDist = d + edge.cost;
			if(dist[edge.to] > newDist) {
				dist[edge.to] = newDist;
				pq.push(ii(dist[edge.to], edge.to));
			}
		}
	}	
}

void solve()
{
	scanf("%d %d %d %d", &n, &e, &t, &m);

	for(int i = 0; i < n; i++)
		g[i].clear();

	for(int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;

		g[v].push_back(Edge(u, w)); // fuck this shit...
	}

	// get shortest path from e to all other vertex
	dijkstra(e - 1);

	// get number of vertex dist <= t
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(dist[i] <= t)
			ans++;
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
		if(ncase)
			printf("\n");
	}

	return 0;
}
