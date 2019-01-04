#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    
    int f = n - 1;
    int ans = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(i < f) 
            ans++;
        f = min(i - inp[i], f);
    }
    printf("%d\n", ans);

    return 0;
}
