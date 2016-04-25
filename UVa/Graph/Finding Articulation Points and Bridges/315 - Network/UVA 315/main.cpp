#include <bits/stdc++.h>

using namespace std;

vector<int> g[111];

int T, timestamp[111], low[111], total;
bool isArticulationPoint[111];
/*
   3
   2 1 3
   0
   0
 */
void dfs(int u, int p) 
{
    timestamp[u] = low[u] = T++; 

    int children = 0;
    for(int i = 0; i < (int)g[u].size(); i++) {
	int v = g[u][i];
	if(v != p) {
	    if(timestamp[v] == -1) {
		children++;
		dfs(v, u);

		low[u] = min(low[u], low[v]);
		
		// Update must be here!! See in3 and move this block out after line 37
		/* 
		Only new and direct child can qualify its parent to be the articulation point.
		Because if you can be updated by a node, which isn't parent and already visited, 
		this inferred that you can go back to further point without going through parent
		*/
		if(p == -1 && children >= 2) { // root
		    isArticulationPoint[u] = true;  
		} else if(p != -1 && timestamp[u] <= low[v]) {
		    // if the low of the child can only reach u, then if u is gone, v has no way 
		    // of reaching the nodes above u
		    isArticulationPoint[u] = true;
		}
	    } else {
		low[u] = min(low[u], timestamp[v]);
	    }
	}
    }
}

int main()
{
    char inp[10000];
    while(fgets(inp, 10000, stdin) != NULL && inp[0] != '0') {
	int n;
	sscanf(inp, "%d", &n);
	for(int i = 0; i <= n; i++) {
	    T = 1;
	    total = 0;
	    g[i].clear();
	    timestamp[i] = low[i] = -1;
	    isArticulationPoint[i] = false;
	}

	while(fgets(inp, 10000, stdin) != NULL && inp[0] != '0') {
	    char *str = strtok(inp, " ");
	    int u = atoi(str);

	    while((str = strtok(NULL, " ")) != NULL) {
		int tmp = atoi(str);
		g[u].push_back(tmp);
		g[tmp].push_back(u);
	    }
	}

	dfs(1, -1);
	for(int i = 0; i <= n; i++) 
	    if(isArticulationPoint[i] == true) {
		total++;
	    }
	printf("%d\n", total);
    }

    return 0;
}
