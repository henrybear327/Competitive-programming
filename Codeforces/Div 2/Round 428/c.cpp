#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 100001;
vector<int> g[MAX_N];

ll sum = 0;
double dp[MAX_N];
void dfs(int u, int p, int len)
{
	int cnt = g[u].size() - (p != -1);
    for(auto v : g[u]) {
        if(v == p) 
            continue;
        
        dfs(v, u, len + 1);
		dp[u] += 1.0 / cnt * (dp[v] + 1);
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
	
	memset(dp, 0, sizeof(dp));
    dfs(1, -1, 0);

    // ans
	printf("%.15f\n", dp[1]);
    return 0;
}
