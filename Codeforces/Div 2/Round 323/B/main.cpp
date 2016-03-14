#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int hacked = 0;
    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    bool dir = 1;
    int ans = 0, pos = 0;
    int v[n];
    memset(v, 0, sizeof(v));
    while (hacked < n) {
        if (inp[pos] <= hacked && v[pos] == 0) {
            v[pos] = 1;
            hacked++;
        }

        if (hacked == n)
            break;

        pos = dir ? pos + 1 : pos - 1;

        if (pos == n || pos == -1) {
            if (pos == n)
                pos--;
            else
                pos++;
            dir = !dir;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
