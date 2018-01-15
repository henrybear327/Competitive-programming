#include <bits/stdc++.h>

using namespace std;

int n, k;
bool check(int inp[], int mid)
{
    int cnt = 1;
    int right = inp[0] + mid;
    for (int i = 1; i < n; i++) {
        if (inp[i] <= right) {
            continue;
        }
        right = inp[i] + mid;
        cnt++;
    }

    // printf("%d %d\n", mid, cnt);
    return cnt <= k;
}

int main()
{
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int l = 0, r = 0x3f3f3f3f;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        // printf("%d %d %d\n", l, mid, r);
        // 0 0 0 0 0 0 1 1 1 1 1 1
        if (check(inp, mid))
            r = mid;
        else
            l = mid;
    }
    printf("%d\n", r);

    return 0;
}
