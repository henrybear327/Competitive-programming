#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Data {
    ll pos;
    ll len;
};

map<ll, ll> ext; // {pos, len}
Data inp[800100]; // fuck my life...
int n; 

ll go1()
{
    // map<ll, ll> ext; // {pos, len}
    ext.clear();

    ll mx = inp[0].len;
    ext[inp[0].pos] = 0;
    ext[inp[0].pos + inp[0].len] = inp[0].len;
    for (int i = 1; i < n; i++) {
        mx = max(mx, inp[i].len);

        // R, none
        auto one = max(ext[inp[i].pos + inp[i].len], ext[inp[i].pos] + inp[i].len);

        // L
        auto two = max(ext[inp[i].pos], ext[inp[i].pos - inp[i].len] + inp[i].len);

        ext[inp[i].pos + inp[i].len] = one;
        ext[inp[i].pos] = two;
    }

    for (auto i : ext)
        mx = max(mx, i.second);

    return mx;
}

ll go2()
{
    ext.clear();

    ll mx = inp[0].len;
    ext[inp[0].pos] = 0;
    ext[inp[0].pos - inp[0].len] = inp[0].len;
    for (int i = 1; i < n; i++) {
        mx = max(mx, inp[i].len);

        // R, none
        auto one = max(ext[inp[i].pos], ext[inp[i].pos + inp[i].len] + inp[i].len);

        // L
        auto two = max(ext[inp[i].pos - inp[i].len], ext[inp[i].pos] + inp[i].len);

        ext[inp[i].pos] = one;
        ext[inp[i].pos - inp[i].len] = two;
    }

    for (auto i : ext) {
        mx = max(mx, i.second);
    }

    return mx;
}

void solve()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &inp[i].pos, &inp[i].len);
    sort(inp, inp + n,
    [](const Data &a, const Data &b) {
        return a.pos < b.pos;
    });

    ll mx1 = go1();

    sort(inp, inp + n,
    [](const Data &a, const Data &b) {
        return a.pos > b.pos;
    });

    ll mx2 = go2();

    printf("%lld\n", max(mx1, mx2));
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
