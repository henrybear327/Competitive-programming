#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
        
    ll sum = 0;
    int inp[n];
    bool has_odd = false;
    for(int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        sum += inp[i];
        
        if(inp[i] % 2 == 1)
            has_odd = true;
    }
    
    if(sum % 2 == 1 || has_odd) {
        printf("First\n");
    } else {
        // 8 - 5 = 3
        // 8 - 6 = 2
        
        // 3 - 2 = 1
        // 3 - 1 = 2
        printf("Second\n");
    }
    
    return 0;
}