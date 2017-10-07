#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n + 1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &inp[i]);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(inp[inp[i]] == i)
            ans++;
    }
    
    printf("%d\n", ans / 2);
    
    return 0;
}