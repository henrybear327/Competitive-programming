#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", (n - 1) * (m - 1));

    for (int i = 0; i < (n - 1); i++) {
        int bottom = m * (n - i);
        for (int j = 1; j <= (m - 1); j++) {
            // from bottom
            int pb = bottom - j;
            int pa = pb - (n - i - 1);

            printf("%d %d\n", pa, n - i - 1);
        }
    }
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
