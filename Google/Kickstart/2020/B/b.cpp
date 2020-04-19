#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    ll d;
    scanf("%d %lld", &n, &d);

    ll inp[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &inp[i]);

    for (int i = n - 1; i >= 0; i--) {
        ll quo = d / inp[i];
        d = quo * inp[i];
    }

    printf("%lld\n", d);
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
