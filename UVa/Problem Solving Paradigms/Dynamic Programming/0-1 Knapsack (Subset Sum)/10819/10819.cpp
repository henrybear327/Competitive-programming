// 1801 + 200 -> reward GET!!
#include <bits/stdc++.h>

using namespace std;

struct Data {
    int cost;
    int rank;
};

void solve(int m, int n)
{
    Data inp[n + 1];
    for(int i = 1; i <= n; i++) 
        scanf("%d %d", &inp[i].cost, &inp[i].rank);
    
    int dp[m + 200 + 1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= n; i++) {
        for(int j = m + 200; j >= 0; j--) {
            int target = j + inp[i].cost;
            // coin change DP, with restrictions
            // last condition is the update condition, update table only when the cost is feasible
            if(dp[j] > 0 && target < m + 200 + 1 && (target <= m || target > 2000) ) {
                dp[target] = max(dp[target], dp[j] + inp[i].rank); 
            }
        }
        
        // although this cost might be > m and < 2000, but it might be in combination with other items to make it a valid combination, so add it!
        if(inp[i].cost < m + 200 + 1)
            dp[inp[i].cost] = max(dp[inp[i].cost], inp[i].rank);
    }
    
    int ans = 0;
    for(int i = 0; i < m + 200 + 1; i++) {
        if(i <= m || (i > 2000))
            ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) {
        solve(m, n);
    }

    return 0;
}
