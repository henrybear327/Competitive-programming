#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m)
{
    int heads[n], knights[m];
    for(int i = 0; i < n; i++)
        scanf("%d", &heads[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &knights[i]);

    sort(heads, heads + n);
    sort(knights, knights + m);
    
    int ans = 0;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        while(idx < m && knights[idx] < heads[i]) {
            idx++;
        }

        if(idx == m) {
            printf("Loowater is doomed!\n");
            return;
        }

        ans += knights[idx];
        idx++;
    }

    printf("%d\n", ans);
}

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && (n || m))
        solve(n, m);

    return 0;
}
