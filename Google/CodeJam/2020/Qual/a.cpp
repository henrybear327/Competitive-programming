#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int inp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &inp[i][j]);
            inp[i][j]--;
        }

    int trace = 0;
    for (int i = 0; i < n; i++)
        trace += inp[i][i] + 1;

    int horCount = 0, verCount = 0;
    for (int i = 0; i < n; i++) {
        int seen[n] = {false};
        int seen2[n] = {false};
        for (int j = 0; j < n; j++) {
            // hor
            if ((inp[i][j] >= n || inp[i][j] < 0) || seen[inp[i][j]]) {
                horCount++;
                break;
            } else {
                seen[inp[i][j]] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            // ver
            if ((inp[j][i] >= n || inp[j][i] < 0) || seen2[inp[j][i]]) {
                verCount++;
                break;
            } else {
                seen2[inp[j][i]] = true;
            }
        }
    }

    printf("%d %d %d", trace, horCount, verCount);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }

    return 0;
}
