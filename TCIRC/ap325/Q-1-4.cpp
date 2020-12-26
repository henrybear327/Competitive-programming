#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef long long int ll;

vector<ll> pre;
ll solve(int l, int r, int depth, int k, int inp[], int n)
{
    if (r - l < 3) {
        return 0;
    }

    // printf("%d %d\n", l, r);
    if (depth == k) {
        return 0;
    }

    ll mn = LLONG_MAX;
    int who = -1;
    ll left = inp[l];
    ll right = 0;
    for (int i = l + 2; i < r; i++) {
        right += 1LL * inp[i] * (i - (l + 1));
    }

    for (int i = l + 1; i < r - 1; i++) { // left and right bound can not be used
        ll tmp = abs(abs(right) - abs(left));
        if (tmp < mn) {
            mn = tmp;
            who = i;
        }

        left += inp[i];
        left += pre[i - 1] - pre[l - 1];

        right -= pre[r - 1] - pre[i];
    }

    ll idx = inp[who] + solve(l, who, depth + 1, k, inp, n) +
             solve(who + 1, r, depth + 1, k, inp, n);

    return idx;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n + 1];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i + 1]);

    pre.push_back(0);
    for (int i = 0; i < n; i++) {
        pre.push_back(pre[i] + inp[i + 1]);
    }

    ll ret = solve(1, n + 1, 0, k, inp, n);

    printf("%lld\n", ret);

    return 0;
}
