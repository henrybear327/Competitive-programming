#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

#define N 100100

vector<int> g[N];
int seen[N];

int maxNode = 0, maxDist = 0;
void dfs(int u, int l) 
{
    if(seen[u] != -1)
	return;
    seen[u] = l;
    
    for(auto i : g[u]) {
	dfs(i, l + 1);
    }

    if(maxDist < l) {
	maxDist = l;
	maxNode = u;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int deg[N] = {0};
    for(int i = 0; i < k; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	g[u].push_back(v);
	g[v].push_back(u);
	deg[u]++;
	deg[v]++;
    }
    
    memset(seen, -1, sizeof(seen));
    for(int i = 1; i <= n; i++)
	if(deg[i] == 1) {
	    dfs(i, 0);
	    break;
	}
    
    memset(seen, -1, sizeof(seen));
    dfs(maxNode, 0);

    printf("%d\n", maxDist);

    return 0;
}
