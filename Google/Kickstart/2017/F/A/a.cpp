#include <bits/stdc++.h>

using namespace std;

void solve(int ncase)
{
    int n;
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    bool ok = true;    
    {
        int mid = (n - 1) / 2;
        int sz = n;
        int mn = 1, mx = n;
        for(int i = 1; i <= n - 2; i++) {
            if(inp[mid] != mn && inp[mid] != mx) {
                ok = false;
                break;
            }
            
            if(inp[mid] == mx)
                mx--;
            if(inp[mid] == mn)
                mn++;
            
            mid = mid + i * (sz % 2 == 0 ? 1 : -1);
            sz--;
        }
    }
    
    printf("Case #%d: %s\n", ncase, ok ? "YES" : "NO");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    
    for(int i = 0; i < ncase; i++) {
        solve(i + 1);
    }
    
    return 0;
}