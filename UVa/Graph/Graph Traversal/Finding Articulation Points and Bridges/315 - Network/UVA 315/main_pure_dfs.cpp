#include <bits/stdc++.h>

using namespace std;

vector<int> g[111];

bool isArticulationPoint[111];
int ig;
bool visited[111];
void dfs(int u) 
{
    if(visited[u])
	return;
    visited[u] = true;

    for(auto i : g[u]) {
	if(i == ig)
	    continue;
	dfs(i);
    }
}

int main()
{
    char inp[10000];
    while(fgets(inp, 10000, stdin) != NULL && inp[0] != '0') {
	int n;
	sscanf(inp, "%d", &n);
	for(int i = 0; i <= n; i++) {
	    g[i].clear();
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
	
	for(int i = 1; i <= n; i++) {
	    memset(visited, 0, sizeof(visited));
	    ig = i;
	    dfs(g[i][0]); // watch out!!
	    for(int j = 1; j <= n; j++)
		if(i != j && visited[j] == false) {
		    isArticulationPoint[i] = true;
		    break;
		}
	}
	
	int total = 0;
	for(int i = 0; i <= n; i++) 
	    if(isArticulationPoint[i] == true) {
		total++;
	    }
	printf("%d\n", total);
    }

    return 0;
}
