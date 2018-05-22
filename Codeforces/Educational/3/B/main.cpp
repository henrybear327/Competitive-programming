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
    int n, m;
    scanf("%d %d", &n, &m);

    int genre[m + 1];
    memset(genre, 0, sizeof(genre));
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        genre[tmp]++;
    }

    long long int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j)
                continue;
            ans += (genre[i] * genre[j]);
        }
    }
    printf("%lld\n", ans / 2);

    return 0;
}
