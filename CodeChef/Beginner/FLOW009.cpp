#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    double res = 0;
    int q, p;
    scanf("%d %d", &q, &p);

    res += ((q > 1000) ? p * 0.9 : p) * q;

    printf("%f\n", res);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
