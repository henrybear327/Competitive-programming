#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int mod[k] = {0};
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        mod[num % k]++;
    }

    ll ans = 0;
    for (int i = 1; i < (k + 1) / 2; i++) {
        int mn = min(mod[i], mod[k - i]);
        ans += mn;
    }
    if (k % 2 == 0)
        ans += mod[k / 2] / 2;

    ans += mod[0] / 2;

    printf("%lld\n", ans * 2);

    return 0;
}
