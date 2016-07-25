#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const ll target = (ll)1e9;

int main()
{
    ll n;
    scanf("%lld", &n);

    if(n <= 4) {
        printf("-1\n");
        return 0;
    }

    ll cnt = 0;
    ll ans = 0;
    while(cnt < target) {
        ll mul, mul1;
        mul = n / 2;
        mul1 = n - mul;

        ll cur = mul * mul1;

        cnt += cur;
        ans++;
        n = cur;
    }

    printf("%lld\n", ans);

    return 0;
}