#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector<vector<char>> ans(111, vector<char>(111, '.'));
    int inp[n], l = 0;
    int mx = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);

        if (inp[i] == 0)
            continue;

        for (int j = l; j < l + inp[i]; j++) {
            int diff = abs(i - j);
            if (diff == 0)
                continue;

            if (j < i) { // from left
                int row = 0, col = j;
                for (int k = 0; k < diff; k++) {
                    ans[row + k][col + k] = '\\';
                    mx = max(mx, row + k + 2);
                }
            } else { // from right
                int row = 0, col = j;
                for (int k = 0; k < diff; k++) {
                    ans[row + k][col - k] = '/';
                    mx = max(mx, row + k + 2);
                }
            }
        }

        l += inp[i];
    }

    if (inp[0] == 0 || inp[n - 1] == 0) {
        printf("IMPOSSIBLE\n");
        return;
    }

    printf("%d\n", mx);
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
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