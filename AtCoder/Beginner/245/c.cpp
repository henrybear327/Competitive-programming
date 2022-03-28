#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i][1]);
    }

    bool ok[n][2];
    memset(ok, false, sizeof(ok));
    ok[0][0] = true;
    ok[0][1] = true;
    for (int i = 1; i < n; i++) {
        if (ok[i - 1][0]) {
            if (abs(inp[i][0] - inp[i - 1][0]) <= k) {
                ok[i][0] = true;
            }

            if (abs(inp[i][1] - inp[i - 1][0]) <= k) {
                ok[i][1] = true;
            }
        }

        if (ok[i - 1][1]) {
            if (abs(inp[i][0] - inp[i - 1][1]) <= k) {
                ok[i][0] = true;
            }

            if (abs(inp[i][1] - inp[i - 1][1]) <= k) {
                ok[i][1] = true;
            }
        }
    }

    if (ok[n - 1][0] || ok[n - 1][1]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
