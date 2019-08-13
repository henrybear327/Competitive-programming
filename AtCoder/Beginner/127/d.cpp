#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    ii op[m];
    for (int i = 0; i < m; i++)
        scanf("%d %d", &op[i].second, &op[i].first);

    sort(op, op + m,
         [](const ii a, const ii b) -> bool { return a.first > b.first; });

    int idx = 0;
    for (int i = 0; idx < n && i < m; i++) {
        int val = op[i].first;
        for (int j = 0; idx < n && j < op[i].second; j++) {
            if (inp[idx] < val) {
                inp[idx] = val;
                idx++;
            } else {
                goto done;
            }
        }
    }

done:
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += inp[i];
    printf("%lld\n", ans);

    return 0;
}
