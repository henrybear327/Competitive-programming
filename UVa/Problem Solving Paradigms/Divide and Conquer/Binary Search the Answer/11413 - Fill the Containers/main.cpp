#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

bool check(ll mid, int inp[], int n, int m)
{
    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + inp[i] <= mid) {
            sum += inp[i];
        } else {
            if (cnt == m - 1)
                return false;
            else {
                cnt++;
                sum = 0;
                if (sum + inp[i] <= mid)
                    sum = inp[i];
                else
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        ll l = 0, r = LLONG_MAX;
        while (r - l > 1) {
            ll mid = l + (r - l) / 2;

            if (check(mid, inp, n, m))
                r = mid;
            else
                l = mid;
        }

        printf("%lld\n", r);
    }

    return 0;
}
