#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int n;
ll d, inp[100010];
bool check(ll mid)
{
    ll prev = inp[0] + mid * d;
    for(int i = 1; i < n; i++) {
        ll k = (prev - inp[i]) / d;
        if(prev <= inp[i] + k * d) // fuck you
            k--;

        k = min(mid, abs(k)) * (k >= 0 ? 1 : -1);

        // both must be same odd/even property
        if(abs(k) % 2 == 0 && mid % 2 == 1)
            k--;
        if(abs(k) % 2 == 1 && mid % 2 == 0)
            k--;

        if(inp[i] + k * d >= prev || abs(k) > mid)
            return false;

        prev = inp[i] + k * d;
    }
    return true;
}

int main()
{
    scanf("%d %lld", &n, &d);

    for(int i = 0; i < n; i++)  {
        scanf("%lld", &inp[i]);
    }

    ll l = -1, r = ((ll)1e18 - inp[0]) / d + 1;
    while(r - l > 1LL) {
        ll mid = l + (r - l) / 2;
        //printf("%lld %lld %lld %d\n", l, r, mid, check(mid));

        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%lld\n", r);

    return 0;
}