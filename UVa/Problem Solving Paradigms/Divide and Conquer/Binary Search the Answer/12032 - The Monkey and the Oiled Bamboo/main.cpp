#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int inp[], int n)
{
    for (int i = 0; i < n; i++) {
        if (inp[i] - inp[i - 1] == mid)
            mid--;
        else if (inp[i] - inp[i - 1] < mid)
            continue;
        else
            return false;
    }

    return true;
}

int solve()
{
    int n;
    scanf("%d", &n);
    n++;

    int inp[n];
    inp[0] = 0;
    for (int i = 1; i < n; i++)
        scanf("%d", &inp[i]);

    int l = 0, r = 0x3f3f3f3f;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(mid, inp, n))
            r = mid;
        else
            l = mid;
    }

    return r;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        int ret = solve();
        printf("Case %d: %d\n", i, ret);
    }

    return 0;
}
