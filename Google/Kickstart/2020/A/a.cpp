#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, b;
    scanf("%d %d", &n, &b);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + n);

    int ans = 0;
    while (ans < n && b - inp[ans] >= 0) {
        b -= inp[ans];
        ans++;
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case #%d: %d\n", i, solve());

    return 0;
}
