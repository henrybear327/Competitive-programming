#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// http://kuoe0.logdown.com/posts/2011/05/01/poj-2231-moo-volume
int main()
{
    int ncase;
    scanf("%d", &ncase);
    
    while(ncase--) {
        int n;
        scanf("%d", &n);
        
        ll ans = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            ll tmp;
            scanf("%lld", &tmp);
            ans = max(ans, tmp);
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}