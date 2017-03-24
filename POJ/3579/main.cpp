#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 100100;
int n, inp[N];

// true if median > x
ll check(int x)
{
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n; // [l, r)

        while (r - l > 1) {
            int mid = (l + r) / 2;
            // printf("before %d mid = %d, %d %d %d\n", i, x, l, mid, r);

            if (inp[mid] - inp[i] <= x)
                l = mid;
            else
                r = mid;

            // printf("after %d mid = %d, %d %d %d\n", i, x, l, mid, r);
        }

        // l
        ans += l - i;
    }

    return ans;
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &inp[i]);
        }
        sort(inp, inp + n);

        int l = 0, r = inp[n - 1] - inp[0];
        ll total = ((ll)n * (n - 1)) / 2;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;

            ll val = check(mid);
            // printf("before %d %d %d %lld\n", l, mid, r, val);
            if (val < (total + 1) / 2) { // this equal sign is fucking crucial -> try 2 2 3 9
                l = mid;
            } else {
                r = mid;
            }
            // printf("after %d %d %d %lld\n", l, mid, r, val);
        }

        // printf("l = %d\n", l);

        printf("%d\n", l + (check(l) < (total + 1) / 2));
    }

    return 0;
}
