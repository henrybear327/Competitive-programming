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

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        mp[tmp] = i;
    }

    long long int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += abs(mp[i] - mp[i - 1]);
    }
    printf("%lld\n", ans);

    return 0;
}
