#include <bits/stdc++.h>

using namespace std;

void solve(int ncase)
{
    printf("Case %d: ", ncase);
    
    int r, c, m, n;
    scanf("%d %d %d %d", &r, &c, &m, &n);

    int g[r][c];
    memset(g, 0, sizeof(g));

    int w;
    scanf("%d", &w);
    for(int i = 0; i < w; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        g[x][y] = 1;
    }       
    
    
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for(int i = 1; i <= ncase; i++)
        solve(i);

    return 0;
}
