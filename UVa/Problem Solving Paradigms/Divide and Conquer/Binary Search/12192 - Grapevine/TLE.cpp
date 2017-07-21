#include <bits/stdc++.h>

using namespace std;

int n, m;
int inp[555][555];
int low, high;

bool check(int mid)
{
    for(int i = 0; i + mid - 1 < n; i++)
        for(int j = 0; j + mid - 1 < m; j++) {
            if(low <= inp[i][j] && inp[i + mid - 1][j + mid - 1] <= high) {
                // printf("%d %d %d %d\n", low, inp[i][j], inp[i + mid][j + mid], high);
                // printf("mid %d: %d %d\n", mid, i, j);
                return true;
            }
        }
    return false;
}

void solve()
{
    int l = 0, r = min(n, m) + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        // printf("l %d r %d mid %d\n", l, r, mid);
        
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    
    printf("%d\n", l);
}

int main()
{
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                scanf("%d", &inp[i][j]);
        
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &low, &high);
            
            solve();
        }
        printf("-\n");
    }
    
    return 0;
}