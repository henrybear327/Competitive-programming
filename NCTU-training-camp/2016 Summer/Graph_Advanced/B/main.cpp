#include <bits/stdc++.h>

using namespace std;

#define N 100010
vector<int> g[N];
int orig[N], final[N];

vector<int> ans;

void dfs(int u, int p, int odd, int even, int level)
{
    int cur = orig[u];
    if(level % 2 == 0 && even % 2 == 1)
	cur ^= 1;
    else if(level % 2 == 1 && odd % 2 == 1)
	cur ^= 1;

    if(cur != final[u]) {
	ans.push_back(u);
	if(level % 2 == 0)
	    even++;
	else
	    odd++;
    }

    for(auto v : g[u]) {
	if( v == p )
	    continue;
	dfs(v, u, odd, even, level + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	u--;
	v--;

	g[u].push_back(v);
	g[v].push_back(u);
    }
    
    for(int i = 0; i < n; i++)
	scanf("%d", &orig[i]);
    for(int i = 0; i < n; i++)
	scanf("%d", &final[i]);

    dfs(0, -1, 0, 0, 0);
    
    printf("%d\n", (int)ans.size());
    for(auto i : ans)
	printf("%d\n", i + 1);

    return 0;
}
