#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll negSum = 0;
ll posSum = 0;

ll go(ll n, ll m, vector<ii> &inp)
{
    ll neg = ((n - 1) / 2) * ll((n - 1) / 2 + 1);
    if (n % 2 == 0)
        neg += n / 2;
    ll pos = n * ll(n - 1) / 2;

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll x = inp[i].first;
        ll d = inp[i].second;
        ans += x * ll(n);
        if (d < 0) {
            ans += neg * d;
            negSum += neg * d;
        } else {
            ans += pos * d;
            posSum += pos * d;
        }
    }

    return ans;
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll oddSum = 0;
    ll evenSum = 0;
    ll sum = 0;
    vector<ii> inp;
    for (int i = 0; i < m; i++) {
        ll x, k;
        scanf("%lld %lld", &x, &k);
        inp.push_back(ii(x, k));

        sum += x * n;
        if (k >= 0) {
            oddSum += ((n - 1) * n) / 2LL * k;
            // printf("k >= 0 %lld\n", oddSum);
        } else {
            bool even = (n % 2 == 0);
            if (even)
                n--;
            ll cnt = n / 2LL;
            ll inc = (1LL + cnt) * cnt;
            if (even) {
                n++;
                cnt = n / 2LL;
                inc += cnt;
            }
            evenSum += inc * k;
            // printf("k < 0 %lld\n", evenSum);
        }
    }

    ll total = oddSum + evenSum + sum;

    ll correct = go(n, m, inp);

    if (total != correct) {
        printf("%lld %lld\n", total, correct);
        printf("%lld %lld\n", oddSum, evenSum);
        printf("%lld %lld\n", posSum, negSum);
    }

    printf("%.15f\n", double(total) / n);

    return 0;
}
