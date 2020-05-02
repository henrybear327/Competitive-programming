#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, d;
    scanf("%d %d", &n, &d);

    ll inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &inp[i]);
    }
    sort(inp, inp + n);

    int ans = INT_MAX;

    // use 1
    ans = d - 1;

    // use 2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d == 3) {
                if (inp[i] * 2 < inp[j])
                    ans = min(ans, 2);
                if (inp[i] * 2 == inp[j])
                    ans = min(ans, 1);
            }

            if (d == 2) {
                if (inp[i] < inp[j])
                    ans = min(ans, 1);
                if (inp[i] == inp[j])
                    ans = min(ans, 0);
            }
        }
    }

    // case 3 n n n
    if (d == 3) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++) {
                    if (inp[i] == inp[j] && inp[j] == inp[k])
                        ans = 0;
                    else if (inp[i] == inp[j])
                        ans = min(ans, 1);
                    else
                        ans = min(ans, 2);
                }
    }
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
