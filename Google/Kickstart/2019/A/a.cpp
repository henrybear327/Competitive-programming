#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, p;
    scanf("%d %d", &n, &p);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int ans = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < p - 1; i++)
        cnt += inp[i];

    for (int i = p - 1; i < n; i++) {
        int sum = inp[i] * p;
        cnt += inp[i];
        if (i - p >= 0)
            cnt -= inp[i - p];
        ans = min(ans, sum - cnt);
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
