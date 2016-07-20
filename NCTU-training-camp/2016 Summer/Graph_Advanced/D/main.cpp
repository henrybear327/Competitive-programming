#include <bits/stdc++.h>

using namespace std;

#define N 200010

typedef pair<int, int> ii;

vector<int> g[N];
set< ii > orig;

int totalUp;
int up[N], level[N];

void dfs(int u, int p)
{
    for(auto v : g[u]) {
	if(v == p)
	    continue;
	
	// get type
	bool isUp = false;
	if(orig.find(ii(u, v)) == orig.end())
	    isUp = true;
	totalUp += (isUp == true ? 1 : 0);
	level[v] = level[u] + 1;
	up[v] = up[u] + (isUp == true ? 1 : 0);

	dfs(v, u);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	g[u].push_back(v);
	g[v].push_back(u);

	orig.insert(ii(u, v));
    }

    totalUp = 0;
    memset(up, -1, sizeof(up));
    memset(level, -1, sizeof(level));
    up[1] = 0;
    level[1] = 0;
    dfs(1, -1);
    
    int mn = INT_MAX;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
	if(mn > totalUp - 2 * up[i] + level[i]) {
	    mn = totalUp - 2 * up[i] + level[i];
	    ans.clear();
	    ans.push_back(i);
	} else if(mn == totalUp - 2 * up[i] + level[i])
	    ans.push_back(i);
    }
    
    printf("%d\n", mn);
    for(auto i : ans)
	printf("%d ", i);

    return 0;
}
