#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ll ans = 0;
    int inp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &inp[i][j]), ans += inp[i][j];

    while (true) {
        bool cont = false;
        bool bye[n][m];
        memset(bye, false, sizeof(bye));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (inp[r][c] > 0) {
                    int left = -1;
                    int right = -1;
                    int top = -1;
                    int bottom = -1;

                    // has row
                    for (int i = 0; i < m; i++) {
                        if (i == c)
                            continue;

                        if (inp[r][i] > 0) {

                            if (i < c)
                                left = i;
                            else if (i > c && right == -1)
                                right = i;
                        }
                    }

                    // has col
                    for (int i = 0; i < n; i++) {
                        if (i == r)
                            continue;

                        if (inp[i][c] > 0) {

                            if (i < r)
                                top = i;
                            else if (i > r && bottom == -1)
                                bottom = i;
                        }
                    }

                    int sum = 0;
                    int cnt = 0;
                    if (top != -1)
                        sum += inp[top][c], cnt++;
                    if (bottom != -1)
                        sum += inp[bottom][c], cnt++;
                    if (left != -1)
                        sum += inp[r][left], cnt++;
                    if (right != -1)
                        sum += inp[r][right], cnt++;
                    // printf("%d %d %d %d\n", left, right, top, bottom);
                    // printf("%d %d, %d %d\n", r, c, sum, cnt);
                    double avg = 1.0 * sum / cnt;
                    if (avg > inp[r][c])
                        bye[r][c] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (bye[i][j]) {
                    cont = true;
                    inp[i][j] = -1;
                }
            }

        if (cont) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (inp[i][j] > 0)
                        ans += inp[i][j];
        }

        /*
        printf("\n");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                printf("%d%c", inp[i][j], j == m - 1 ? '\n' : ' ');
        printf("\n");
        */
        if (cont == false)
            break;
    }

    printf("%lld", ans);
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
