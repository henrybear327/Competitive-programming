#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cal(ll i, ll n)
{
    ll ret = 0;
    ll diff = i;
    ll quantity = n / i;

    ret = (1 + (1 + n - diff)) * quantity / 2;
    // printf("%d %lld\n", i, ret);
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);

    /*
       for (int k = 1; k <= n; k++) {
       printf("k = %d: ", k);

       int pos = 1;
       int ans = 0;
       do {
       ans += pos;
       pos += k;
       if (pos > n)
       pos = (pos - 1) % n + 1;
       } while (pos != 1);

       printf("%d\n", ans);
       }
     */

    set<ll> ans;
    int n2 = n / 2;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll ret = cal(i, n);
            ans.insert(ret);

            if (n % (n / i) == 0) {
                ret = cal(n / i, n);
                ans.insert(ret);
            }
        }
    }

    for (auto i : ans)
        printf("%lld ", i);

    return 0;
}
