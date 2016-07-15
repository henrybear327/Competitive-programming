#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4 + 9, K = 509;
int n, k, a, b, dp[MAX][K];
vector<int> g[MAX];
long long ans = 0;
void dfs(int u, int p = -1)
{
    dp[u][0] = 1;
    for (auto v : g[u])
        if (v != p) {
            dfs(v, u);
            for (int i = 0; i <= k; i++)
                ans += 1LL * dp[u][i] * dp[v][k - i - 1];

	    // update
            for (int i = 0; i <= k; i++)
                dp[u][i + 1] += dp[v][i];
	    
	    printf("\n");
	    printf("u %d\n", u);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < k; j++)
                    printf("%d%c", dp[i][j], j == k - 1 ? '\n' : ' ');
	    printf("\n");
        }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
        cin >> a >> b, a--, b--, g[a].push_back(b), g[b].push_back(a);
    dfs(0);
    cout << ans;
}
