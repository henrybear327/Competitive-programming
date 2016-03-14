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

    int inp[n], idx = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        if (idx == -1 && inp[i] == 1)
            idx = i;
    }

    if (idx == -1) {
        printf("0\n");
        return 0;
    }

    long long int ans = 0, cnt;
    for (int i = idx + 1; i < n; i++) {
        if (inp[i] == 1) {
            if (ans == 0) {
                ans = i - idx;
            } else {
                ans *= (i - idx);
            }
            idx = i;
        } else {
            cnt++;
        }
    }
    printf("%lld\n", ans == 0 ? 1 : ans);

    return 0;
}
