#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ok(ll x)
{
    if (x % 9 == 0)
        return false;
    while (x > 0) {
        if (x % 10 == 9)
            return false;
        x /= 10;
    }
    return true;
}

ll f(ll x)
{
    // get valid number count
    ll xx = x - x % 10;
    ll cnt = 0;
    for (ll i = 1; xx > 0; xx /= 10, i *= 9) {
        cnt += (xx % 10) * i;
    }

    // remove multiple of 9 count
    cnt = cnt * 8 / 9;

    // enumerate the remaining interval
    for (ll i = x - x % 10; i <= x; i++) {
        if (ok(i))
            cnt++;
    }

    return cnt;
}

ll solve()
{
    ll a, b;
    cin >> a >> b;

    return f(b) - f(a) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ncase;
    cin >> ncase;
    for (int i = 1; i <= ncase; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}
