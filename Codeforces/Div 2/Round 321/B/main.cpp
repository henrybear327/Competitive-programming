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
    int n, d;
    scanf("%d %d", &n, &d);

    pair<long long int, long long int> inp[100010];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }

    sort(inp, inp + n);

    long long int ans = 0, cur = 0;

    int r = 0;
    for (int i = 0; i < n; i++) {
        while (r < n && inp[r].first - inp[i].first < d) {
            cur += inp[r].second;
            r++;
        }
        ans = max(ans, cur);
        cur -= inp[i].second;
    }

    printf("%lld\n", ans);

    return 0;
}
