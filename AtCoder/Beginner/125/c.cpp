#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int suf[n + 1];
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suf[i] = gcd(suf[i + 1], inp[i]);

    int g = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = gcd(g, suf[i + 1]);
        ans = max(ans, tmp);
        g = gcd(g, inp[i]);
    }
    printf("%d\n", ans);

    return 0;
}
