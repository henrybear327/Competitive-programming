#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dp[50010][500];
vector<int> g[50010];

ll ans;
int n, k;
void dfs(int u, int p)
{
    dp[u][0] = 1;
    for(auto v : g[u]) {
	if(v == p)
	    continue;
	
	dfs(v, u);
	
	// k - 1 = i + (k - i - 1)
	// two nodes sharing an edge will have a diatance of 1, 
	// so k - i + i - 1 is the distance to look for
	for(int i = 0; i <= k - 1; i++) {
	     ans += dp[u][i] * dp[v][k - i - 1];
	}
	
	// update
	for(int i = 1; i < k; i++) {
	    dp[u][i] += dp[v][i - 1];
	}
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    ans = 0;
    dfs(1, -1);

    printf("%lld\n", ans);

    return 0;
}
