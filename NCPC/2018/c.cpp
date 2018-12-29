#include <bits/stdc++.h>

using namespace std;

// Andy 0:17
// Thanks Testcase 3
void solve()
{
    int k, r;
    scanf("%d %d", &k, &r);

    int ans = k;
    for (int i = 0; i < r; i++) {
        if ((k + 3) % 4 == 0) {
            if (k > 2 && (k + 3) / 2 < k - 2)
                k -= 2;
            else
                k += 3;
        } else {
            k += 3;
        }

        if (k % 4 == 0)
            k /= 2;

        ans = max(ans, k);
    }
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
