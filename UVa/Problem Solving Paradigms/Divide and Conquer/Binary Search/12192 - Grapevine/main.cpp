#include <bits/stdc++.h>

// For every query, binary search for the upper-left corner of the square
// And then binary search for the lower-left corner "on the diagnal"

using namespace std;

int n, m;
int inp[555][555];
int low, high;

int search(int row, int col)
{
    // printf("row %d col %d\n", row, col);
    int l = -1, r = min(n - row, m - col);
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        // printf("l = %d, mid = %d, r = %d\n", l, mid, r);
        
        if(inp[row + mid][col + mid] <= high)
            l = mid;
        else
            r = mid;
    }
    // printf("l = %d\n", l);
    
    return l;
}

void solve()
{
    int ret = 0;
    for(int i = 0; i < n; i++) {
        int l = lower_bound(inp[i], inp[i] + m, low) - inp[i];
        if(l == m)
            continue;
        int r = search(i, l);
        if(r == -1)
            continue;
        // printf("i = %d l = %d r = %d\n", i, l, r);
        
        ret = max(ret, r + 1);
    }
    
    printf("%d\n", ret);
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