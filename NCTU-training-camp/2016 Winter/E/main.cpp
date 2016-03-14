#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int val[20];
ll cal(int n, int permute[])
{
    /*
    for(int i = 0; i < n; i++)
        printf("%d%c", permute[i], i == n - 1 ? '\n' : ' ');
    printf("\n");
    */
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        //printf("%lld %d\n", ans, val[permute[i]]);
        ans += (ans + val[permute[i]] - 1LL) % (long long)val[permute[i]];
        //printf("ans %lld\n", ans);
    }
    //printf("\n");
    //printf("ans %lld\n====\n", ans);
    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%d", &val[i]);

        int permute[n];
        for(int i = 0; i < n; i++)
            permute[i]  = i;

        ll mx = LLONG_MIN;
        do {
            mx = max(mx, cal(n, permute));
        } while(next_permutation(permute, permute + n));

        printf("%lld\n", mx);
    }

    return 0;
}