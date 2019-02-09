#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        sum += inp[i].first;
    }

    sort(inp, inp + n, [](const ii &a, const ii &b) {
        int da = a.first - a.second;
        int db = b.first - b.second;
        return da > db;
    });

    int ans = 0;
    for (int i = 0; i < n && sum > m; i++) {
        int diff = inp[i].first - inp[i].second;
        sum -= diff;
        ans++;
    }

    if (sum <= m)
        printf("%d\n", ans);
    else
        printf("-1\n");

    return 0;
}
