#include <bits/stdc++.h>

using namespace std;

// 2:08 1AC

typedef long long ll;

ll cal(ll mid, int inp[], int n)
{
    ll cnt = 0;
    if (mid < 0)
        return 0;

    for (int i = 0; i < n; i++) {
        cnt += mid / inp[i] + 1;
    }
    return cnt;
}

bool check(ll mid, int inp[], int b, int n)
{
    ll cnt = cal(mid, inp, b);
    return n <= cnt;
}

void solve()
{
    int b, n;
    scanf("%d %d", &b, &n);

    int inp[b];
    for (int i = 0; i < b; i++)
        scanf("%d", &inp[i]);

    ll l = -1, r = 1e15;
    while (r - l > 1) {
        ll mid = (l + r) / 2;

        // <<<<<<<<>>>>>>
        if (check(mid, inp, b, n))
            r = mid;
        else
            l = mid;
    }

    // r - 1
    ll acc = cal(r - 1, inp, b);
    for (int i = 0; i < b; i++) {
        if (r % inp[i] == 0)
            acc++;

        if (acc == n) {
            printf("%d\n", i + 1);
            return;
        }
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
