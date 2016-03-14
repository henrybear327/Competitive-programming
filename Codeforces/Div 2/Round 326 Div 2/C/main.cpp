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

    long long int cnt[1001010] = {0};
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    for (int i = 0; i < 1001010; i++) {
        if (cnt[i] >= 2) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
        }
    }

    int ans = 0;
    for (int i = 0; i < 1001010; i++) {
        if (cnt[i])
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
