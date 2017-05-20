#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

void solve()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    int g = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        g = gcd(g, inp[i]);
    }

    for (int i = 0; i < n; i++)
        printf("%d%c", inp[i] / g, i == n - 1 ? '\n' : ' ');
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
