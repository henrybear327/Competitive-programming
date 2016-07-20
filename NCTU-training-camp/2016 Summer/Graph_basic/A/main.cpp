#include <bits/stdc++.h>

using namespace std;

#define N 100010
vector<int> g[N];
int cat[N];
int ans = 0;
int n, m;
void dfs(int u, int p, int cnt)
{
    if(cnt > m) 
	return;
    if((int)g[u].size() == 1 && p != -1) { // leaf... come on!
	ans++;
	return;
    }

    for(auto v : g[u]) {
	if(v == p)
	    continue;
	dfs(v, u, cat[v] == 1 ? cnt + 1 : 0);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
	scanf("%d", &cat[i]);
    
    for(int i = 0; i < n - 1; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	u--;
	v--;

	g[u].push_back(v);
	g[v].push_back(u);
    }

    dfs(0, -1, cat[0]);

    printf("%d\n", ans);

    return 0;
}
