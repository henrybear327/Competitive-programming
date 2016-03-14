#include <cstdio>
#include <cstdlib>

// Must do from the furthest point
// Because the travel dist. to inner most point can save more distance!

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int mid = n / 2;

    long long int ans = 0;
    // right
    int cnt = 0, idx = 0;
    for (int i = 0; i < mid; i++) {
        if (cnt < m) {
            cnt++;
        } else {
            ans += abs(inp[idx] - inp[mid]);
            i--;
            idx = i + 1;
            cnt = 0;
        }
    }

    if (cnt) {
        ans += abs(inp[idx] - inp[mid]);
    }

    cnt = 0;
    idx = n - 1;
    for (int i = n - 1; i > mid; i--) {
        if (cnt < m) {
            cnt++;
        } else {
            ans += abs(inp[idx] - inp[mid]);
            i++;
            idx = i - 1;
            cnt = 0;
        }
    }

    if (cnt) {
        ans += abs(inp[idx] - inp[mid]);
    }
    /*
    10 1
    -1000000000 -1000000000 -1000000000 -1000000000 -1000000000 1000000000
    1000000000 1000000000 1000000000 1000000000
    */
    printf("%lld\n", 2 * ans);

    return 0;
}
