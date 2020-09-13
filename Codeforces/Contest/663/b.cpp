#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    auto solve=[](){
        int n, m;
        scanf("%d %d", &n, &m);

        char inp[n][m + 2];
        for(int i = 0; i < n; i++)
            scanf("%s", inp[i]);

        int ans = 0;
        for(int i = 0; i < m - 1; i++)
            if(inp[n - 1][i] != 'R')
                ans++;
        for(int i = 0; i < n - 1; i++)
            if(inp[i][m - 1] != 'D')
                ans++;

        printf("%d\n", ans);
    };

    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
        solve();   
    }

    return 0;
}
