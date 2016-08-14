#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000
vector<int> g[SIZE];

int T, timestamp[SIZE], low[SIZE];
vector< pair<int, int> > cutEdge;

void dfs(int u, int p)
{
    timestamp[u] = low[u] = T++;

    for(auto v : g[u]) {
	if(v != p) {
	    if(timestamp[v] == -1) {
		dfs(v, u);

		low[u] = min(low[u], low[v]);

		if(timestamp[u] < low[v]) // this condition is sufficient enough, because the child can't even get back to its parent
		    cutEdge.push_back(make_pair(min(u, v), max(u, v)));
	    } else {
		low[u] = min(low[u], timestamp[v]);
	    }
	}
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1){
	if(n == 0) {
	    printf("0 critical links\n\n");
	    continue;
	}

	for(int i = 0; i < n; i++) {
	    g[i].clear();
	}
	T = 0;
	fill(timestamp, timestamp + SIZE, -1);
	fill(low, low + SIZE, -1);
	cutEdge.clear();

	for(int i = 0; i < n; i++) {
	    int u, cnt;
	    scanf("%d (%d)", &u, &cnt);

	    for(int j = 0; j < cnt; j++) {
		int tmp;
		scanf("%d", &tmp);
		g[u].push_back(tmp);	
	    }
	}
	
	/*
	for(int i = 0; i < n; i++) {
	    printf("%d: ", i);
	    for(int j = 0; j < (int)g[i].size(); j++)
		printf("%d, ", g[i][j]);
	    printf("\n");
	}
	*/

	for(int i = 0; i < n; i++) {
	    if(timestamp[i] == -1) {
		dfs(i, -1);
	    }
	}
	
	printf("%d critical links\n", (int)cutEdge.size());
	sort(cutEdge.begin(), cutEdge.end());
	for(int i = 0; i < (int)cutEdge.size(); i++)
	    printf("%d - %d\n", cutEdge[i].first, cutEdge[i].second);
	printf("\n");
    }
    
    return 0;
}
