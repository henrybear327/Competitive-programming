#include <bits/stdc++.h>

using namespace std;

// hahaha long long... QQ
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    ll total = 0;
    ll can[n];
    for(int i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);

        total += a;
    }

    for(int i = 0; i < n; i++)
        scanf("%lld", &can[i]);

    sort(can, can + n);
    
    if(can[n - 1] + can[n - 2] >= total)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
