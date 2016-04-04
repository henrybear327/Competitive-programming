#include <bits/stdc++.h>

using namespace std;

vector<int> g[26];
bool has[26];
int tree, acorn;
bool has_cycle, visited[26];

void dfs(int u, int par)
{
    visited[u] = true;
    for(int i : g[u]) {
	if(visited[i] == true && i != par) {
	    has_cycle = true;
	} else if(visited[i] == false){
	    dfs(i, u);
	}   
    }
}

int main()
{   
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	tree = 0, acorn = 0;
	memset(has, false, sizeof(has));
	for(int i = 0; i < 26; i++)
	    g[i].clear();

	char inp[1000];
	while(scanf("%s", inp) == 1) {
	    if(inp[0] == '*')
		break;
	    g[inp[1] - 'A'].push_back(inp[3] - 'A');
	    g[inp[3] - 'A'].push_back(inp[1] - 'A');
	}
	
	scanf("%s", inp);
	for(int i = 0; inp[i] != '\0'; i++) {
	    if('A' <= inp[i] && inp[i] <= 'Z') {
		has[inp[i] - 'A'] = true;
	    }
	}
	
	for(int i = 0; i < 26; i++) {
	    if(has[i] == true && g[i].size() == 0)
		acorn++;
	}
	
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < 26; i++) {
	    has_cycle = false;
	    if(has[i] == true && g[i].size() > 0 && visited[i] == false) {
		dfs(i, -1);
		if(has_cycle == false)
		    tree++;
	    }
	}
	printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }

    return 0;
}
