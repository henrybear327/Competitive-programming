#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    char in[n + 2], out[n + 2];

    scanf("%s", in);
    scanf("%s", out);

    char ans[n + 2][n + 2];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            ans[i][j] = 'N';

        ans[i][i] = 'Y';
        for (int j = i + 1; j < n; j++) {
            if (in[j] == 'Y' && out[j - 1] == 'Y') {
                ans[i][j] = 'Y';
            } else {
                break;
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            if (in[j] == 'Y' && out[j + 1] == 'Y') {
                ans[i][j] = 'Y';
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%s\n", ans[i]);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: \n", i);
        solve();
    }

    return 0;
}
