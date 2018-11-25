#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll solve()
{
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;

    ll sum = 0;
    // neg
    {
        ll lb = (l % 2 == 1 ? l + 1 : l);
        ll rb = (r % 2 == 1 ? r - 1 : r);
        if (lb <= rb) {
            sum -= (lb + 1 + rb + 1) * ((rb - lb) / 2 + 1) / 2;
        }
    }

    // pos
    {
        ll lb = (l % 2 == 0 ? l + 1 : l);
        ll rb = (r % 2 == 0 ? r - 1 : r);
        if (lb <= rb) {
            sum += (lb + 1 + rb + 1) * ((rb - lb) / 2 + 1) / 2;
        }
    }

    return sum;
}

int main()
{
    //  0 1  2 3  4 5  6
    // -1 2 -3 4 -5 6 -7
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        printf("%lld\n", solve());
    }

    return 0;
}
