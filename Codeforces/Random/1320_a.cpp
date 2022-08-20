#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    scanf("%d", &n);

    map<int, ll> cnt;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        cnt[num - i] += num;
    }

    ll ans = 0;
    for (const auto &tmp : cnt) {
        ans = max(ans, tmp.second);
    }

    printf("%lld\n", ans);

    return 0;
}
