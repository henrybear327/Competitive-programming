#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    // for every number as the starting point
    // get the LIS and LDS
    // LDS can be kept, LIS can be reversed and concatenated to the front of the starting point
    
    // for implementation, reverse the array
    reverse(inp, inp + n);
    int lis[n], lds[n];
    fill(lis, lis + n, 1);
    fill(lds, lds + n, 1);

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            if(inp[j] > inp[i])
                lis[j] = max(lis[j], lis[i] + 1);
            if(inp[j] < inp[i])
                lds[j] = max(lds[j], lds[i] + 1);
        }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
        solve();
        
    return 0;
}
