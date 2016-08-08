#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        ll prefix[n], sum = 0;
        for (int i = 0; i < n; i++) {
            ll cur;
            scanf("%lld", &cur);
            sum += cur;
            if (i == n - 1)
                break;

            prefix[i] = (i == 0 ? cur : prefix[i - 1] + cur);
        }

        ll avg = sum / n;
        for (int i = 0; i < n - 1; i++)
            prefix[i] -= (i + 1) * avg;
        sort(prefix, prefix + n - 1);

        ll mid = prefix[(n - 1) / 2];

        ll res = llabs(mid);
        for (int i = 0; i < n - 1; i++)
            res += llabs(mid - prefix[i]);

        printf("%lld\n", res);
    }

    return 0;
}
