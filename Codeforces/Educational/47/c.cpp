#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    long double sol = 0.0;

    ll oddSum = 0;
    ll evenSum = 0;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll x, k;
        scanf("%lld %lld", &x, &k);

        sum += x;
        if (k >= 0) {
            oddSum += k * (n - 1) * n / 2;
        } else {
            bool even = n % 2 == 0;
            if (even)
                n--;
            int cnt = n / 2;
            ll inc = (k + cnt * k) * cnt;
            evenSum += inc;
            if (even) {
                n++;
                cnt = n / 2;
                evenSum += (cnt * k);
            }
        }
    }

    sol += oddSum + evenSum;
    sol /= n;
    sol += sum;

    printf("%.15Lf\n", sol);

    return 0;
}
