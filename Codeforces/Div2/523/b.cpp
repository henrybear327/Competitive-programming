#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    ll total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        total += inp[i];
    }
    sort(inp, inp + n);

    vector<ii> compressed;
    compressed.push_back(ii(0, 0));
    int cnt = 1, who = inp[0];
    for (int i = 1; i < n; i++) {
        if (inp[i] == who)
            cnt++;
        else {
            compressed.push_back(ii(who, cnt));
            who = inp[i];
            cnt = 1;
        }
    }
    compressed.push_back(ii(who, cnt));

    ll ans = 0;
    int sz = compressed.size();
    int coveredHeight = compressed[sz - 1].first;
    for (int i = sz - 1; i >= 1; i--) {
        int x = compressed[i].second;
        int dh;
        if (coveredHeight >= compressed[i].first) {
            dh = compressed[i].first - compressed[i - 1].first;
        } else {
            dh = coveredHeight - compressed[i - 1].first;
            if (dh < 0)
                dh = 0;
        }
        ans += max(dh, x);
        coveredHeight -= max(dh, x);
    }
    printf("%lld\n", total - ans);

    return 0;
}
