#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n][m], target[n][m];
    int cnt[2] = {0}, cnt2[2] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &inp[i][j]), cnt[inp[i][j] % 2]++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &target[i][j]), cnt2[target[i][j] % 2]++;

    bool ok = true;
    if ((cnt[0] % 2 == cnt2[0] % 2) && (cnt[1] % 2 == cnt2[1] % 2)) {
        for (int i = 0; i < n; i++) {
            int sum = 0, sum2 = 0;
            for (int j = 0; j < m; j++) {
                sum += inp[i][j];
                sum2 += target[i][j];
            }

            if (sum % 2 != sum2 % 2) {
                ok = false;
                goto done;
            }
        }

        for (int j = 0; j < m; j++) {
            int sum = 0, sum2 = 0;
            for (int i = 0; i < n; i++) {
                sum += inp[i][j];
                sum2 += target[i][j];
            }
            if (sum % 2 != sum2 % 2) {
                ok = false;
                goto done;
            }
        }
    } else {
        ok = false;
    }

done:
    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
