#include <cstdio>

int n, s;
bool check(int pre[], int len)
{
    // 0 1 2 3  4  5
    //   1 2 3  4  5
    // 0 1 3 6 10 15
    for (int i = len; i < n + 1; i++) {
        if (pre[i] - pre[i - len] >= s)
            return true;
    }
    return false;
}

void solve()
{
    scanf("%d %d", &n, &s);

    int inp[n + 1];
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &inp[i]);

    int pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + inp[i];

    // min len that has sum >= s
    int l = 1, r = n + 1; // the bound setting is crucial
    while (r - l > 1) {
        int mid = (l + r) / 2;

        // 0 0 0 1 1 1 1 1
        if (check(pre, mid))
            r = mid;
        else
            l = mid;
    }

    printf("%d\n", r == n + 1 ? 0 : r);
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
