#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1000000007;

int main()
{
    int n;
    scanf("%d", &n);

    int cnt[3] = {0};
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        int tmp = 0;
        for (int j = 0; j < 3; j++) {
            if (cnt[j] == num)
                tmp++;
        }

        ans = (ans * tmp) % MOD;

        for (int j = 0; j < 3; j++)
            if (cnt[j] == num) {
                cnt[j]++;
                break;
            }
    }

    printf("%lld\n", ans);

    return 0;
}
