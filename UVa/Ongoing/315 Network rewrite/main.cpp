#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define N 111
vector<int> g[N];
int timer, dfsTime[N], dfsLow[N], root;
bool articulationPoint[N];

// undirected graph
void findArticulationPoint(int u, int p)
{
	dfsTime[u] = dfsLow[u] = timer++;
	
	int child = 0; // root child counter
	for(auto v : g[u]) {
		if(v == p) // don't go back to parent
			continue; 

		if(dfsTime[v] == 0) { 
			child++;
			findArticulationPoint(v, u);
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
			
			// <= for articulation point, < for bridge
			if(dfsTime[u] <= dfsLow[v] && root != u) 
				articulationPoint[u] = true;
			if(u == root && child >= 2) // special case for root
				articulationPoint[u] = true;
		} else { // visited before, back edge
			dfsLow[u] = min(dfsLow[u], dfsTime[v]);
		}
	}
}

int main()
{
	int n;
	char inp[20000];
	fgets(inp, 20000, stdin);
	while(sscanf(inp, "%d", &n) == 1 && n) {
		for(int i = 1; i <= n; i++)
			g[i].clear();

		// read input
		while(fgets(inp, 20000, stdin) != NULL) {
			char *num = strtok(inp, " \r\n");
			int u = atoi(num);
			// printf("u %d\n", u);
			if(u == 0)
				break;
			num = strtok(NULL, " \n\r");
			while(num != NULL) {
				int v = atoi(num);
				// printf("v %d\n", v);
				g[u].push_back(v);
				g[v].push_back(u);
				num = strtok(NULL, " \n\r");
			}
		}

		// find articulation point
		memset(dfsTime, 0, sizeof(dfsTime));
		memset(dfsLow, 0, sizeof(dfsLow));
		memset(articulationPoint, false, sizeof(articulationPoint));

		for(int i = 1; i <= n; i++)
			if(dfsTime[i] == 0) {
				timer = 1;
				root = i;
				findArticulationPoint(i, -1);
			}

		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(articulationPoint[i])
				ans++;
		printf("%d\n", ans);

		fgets(inp, 10000, stdin);
	}

	return 0;
}
