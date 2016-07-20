#include <bits/stdc++.h>

using namespace std;

vector<int> g[222];
    
int ans;
void dfs(int u, int p, int cnt)
{
    for(auto v : g[u]) {
	if(v == p)
	    continue;
	dfs(v, u, cnt + 1);
    }
    ans = max(ans, cnt);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    map<string, int> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
	char inp1[100], inp2[100], inp3[100];
	scanf("%s %s %s", inp1, inp2, inp3);
	
	int len = strlen(inp1);
	for(int j = 0; j < len; j++)
	    if(isupper(inp1[j]))
		inp1[j] = inp1[j] - 'A' + 'a';
	len = strlen(inp3);
	for(int j = 0; j < len; j++)
	    if(isupper(inp3[j]))
		inp3[j] = inp3[j] - 'A' + 'a';
	
	int node1 = -1, node2 = -1;
	auto it = m.begin();
	if( (it = m.find(inp1)) != m.end())
	    node1 = it->second;
	else {
	    node1 = cnt++;
	    m[inp1] = node1;
	}

	if( (it = m.find(inp3)) != m.end())
	    node2 = it->second;
	else {
	    node2 = cnt++;
	    m[inp3] = node2;
	}
	
	g[node1].push_back(node2);
	g[node2].push_back(node1);
    }
    
    int start = m["polycarp"];
    ans = 0;
    dfs(start, -1, 1);

    printf("%d\n", ans);

    return 0;
}
