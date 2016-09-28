#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;

#define N 400
vector<int> g[N];
int timer, dfsTime[N], dfsLow[N], root;
set<ii> bridge;

// undirected graph
void findBridge(int u, int p)
{
	dfsTime[u] = dfsLow[u] = timer++;

	for(auto v : g[u]) {
		if(v == p) // don't go back to parent
			continue; 

		if(dfsTime[v] == 0) { 
			findBridge(v, u);
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);

			// <= for articulation point, < for bridge
			if(dfsTime[u] < dfsLow[v]) 
				bridge.insert(ii(min(u, v), max(u, v)));
		} else { // visited before, back edge
			dfsLow[u] = min(dfsLow[u], dfsTime[v]);
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; i++)
			g[i].clear();

		// read input
		for(int k = 0; k < n; k++) {
			int u, cnt;
			scanf("%d (%d)", &u, &cnt);
			for(int i = 0; i < cnt; i++) {
				int v;
				scanf("%d", &v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}

		// find articulation point
		memset(dfsTime, 0, sizeof(dfsTime));
		memset(dfsLow, 0, sizeof(dfsLow));
		bridge.clear();

		for(int i = 0; i < n; i++)
			if(dfsTime[i] == 0) {
				timer = 1;
				root = i;
				findBridge(i, -1);
			}

		printf("%d critical links\n", (int)bridge.size());
		for(auto i : bridge) {
			printf("%d - %d\n", i.first, i.second);
		}
		printf("\n");
	}

	return 0;
}
