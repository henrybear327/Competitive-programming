#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);
    
    ll inp[n][n];
    ll g[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%lld", &inp[i][j]);
            g[i][j] = inp[i][j];
        }
    
    bool canDelete[n][n];
    memset(canDelete, false, sizeof(canDelete));
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(i != k && k != j && g[i][k] + g[k][j] == inp[i][j]) {
                    // printf("%lld %lld %lld\n", g[i][k], g[k][j], inp[i][j]);
                    // printf("%d %d %d\n", i, k, j);
                    canDelete[i][j] = true;
                }
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }

    ll ans = 0;
    for(int i = 0; i < n && ans != -1; i++)
        for(int j = i + 1; j < n && ans != -1; j++) {
            if(i == j)
                continue;

            if(g[i][j] != inp[i][j]) {
                ans = -1;
                break;
            }

            if(canDelete[i][j] == false)
                ans += g[i][j];
        }

    printf("%lld\n", ans);

    return 0;
}
