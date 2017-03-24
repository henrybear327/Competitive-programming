#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

const int N = 100100;
int n, k;
int data[N];
bool check(int mid)
{
    long long total = 0;
    for (int i = 0; i < n; i++) {
        // formula is curcial
        // k * x + (mid - x) >= data[i]
        // x(k - 1) >= data[i] - mid
        // x >= (data[i] - mid) / (k - 1)

        if (data[i] - mid <= 0)
            continue;

        total += (data[i] - mid) / (k - 1) + ((data[i] - mid) % (k - 1) > 0);
    }

    return total <= mid;
}

int main()
{
    scanf("%d", &n);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", data + i);
        mx = max(mx, data[i]);
    }

    scanf("%d", &k);

    if (k == 1) {
        // special case
        printf("%d\n", mx);
        return 0;
    }

    int l = -1, r = 1e9 + 10;

    while (r - l > 1) {
        int mid = l + (r - l) / 2;

        // 0 0 0 1 1 1 1
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    // r
    printf("%d\n", r);

    return 0;
}
