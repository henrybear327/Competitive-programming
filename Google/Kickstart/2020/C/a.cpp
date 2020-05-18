#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    reverse(inp, inp + n);

    int ans = 0;
    int expect = 1;
    for (int i = 0; i < n; i++) {
        // bug on 3 2 1 2 1 if you put it after line 33
        if (expect != inp[i]) {
            expect = 1;
        }

        if (inp[i] == expect) {
            if (expect == k) {
                ans++;
                expect = 1;
            } else {
                expect++;
            }
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
