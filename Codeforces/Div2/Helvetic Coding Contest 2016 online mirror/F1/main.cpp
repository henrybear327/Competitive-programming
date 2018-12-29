#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

vector<int> g[10010];

int cnt = 0;
void dfs(int u, int par, int step)
{
    if(step == 2) {
	cnt++;
	return;
    }
    for(auto i : g[u]) {
	if(i == par) 
	    continue;
	dfs(i, u, step + 1);
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
    }
    
    for(int i = 1; i <= n; i++) {
	dfs(i, -1, 0);
    }
    printf("%d\n", cnt / 2);
    
    return 0;
}
